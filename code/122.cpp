/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 122.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-05-31
 */
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define foreach(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

typedef long long LL;
typedef pair<int, int> Pii;

const int inf = 0x3f3f3f3f;
const LL infLL = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 1000 + 5;

// forall u, v in V, deg[u] + deg[v] >= N
class Hamilton {
        int n, next[maxn];
        bool g[maxn][maxn], vis[maxn];

        int find(int u)
        {
                for (int v = 0; v < n; ++v)
                        if (g[u][v] && !vis[v]) return v;
                return -1;
        }

        void reverse(int v, int f)
        {
                if (v == -1) return;
                reverse(next[v], v); next[v] = f;
        }

        public:
        void init(int n)
        {
                this->n = n;
                memset(g, false, sizeof(g));
        }

        void add_edge(int u, int v)
        {
                g[u][v] = true;
        }

        void find_path(int s = 0)
        {
                int t = s, sz = 1;
                memset(next, -1, sizeof(next));
                memset(vis, false, sizeof(vis)); vis[s] = true;
                while (sz < n) {
                        if (sz == 1) {
                                for (int v; ~(v = find(s)); s = v)
                                        ++sz, vis[v] = true, next[v] = s;
                                for (int v; ~(v = find(t)); t = v)
                                        ++sz, vis[v] = true, next[t] = v;
                        } else {
                                for (int u, v = 0; v < n; ++v) if (!vis[v]) {
                                        ++sz, vis[v] = true;
                                        for (u = s; !g[u][v]; u = next[u]);
                                        s = next[u]; t = next[u] = v; break;
                                }
                        }
                        if (g[t][s]) next[t] = s;
                        for (int u = next[s], v; next[t] == -1; u = next[u])
                                if (g[u][t] && g[v=next[u]][s])
                                        reverse(v, s), next[u] = t, t = v;
                }
                for (int i = 0, u = 0; i < n; ++i, u = next[u])
                        printf("%d ", u + 1);
                puts("1");
        }
} grp;

bool get_int(int &v, char* &p)
{
        v = 0;
        while (*p && !isdigit(*p)) ++p;
        if (!isdigit(*p)) return false;
        while (isdigit(*p)) v = v * 10 + *p++ - '0';
        return true;
}

int main()
{
        int n;
        scanf("%d\n", &n);
        grp.init(n);
        rep(u,n) {
                int v;
                char buf[10000], *p;
                gets(buf); p = buf;
                while (get_int(v, p)) grp.add_edge(u, --v);
        }
        grp.find_path();

        return 0;
}

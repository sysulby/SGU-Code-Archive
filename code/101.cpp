/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 101.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-05-21
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

const int maxn = 7 + 5;
const int maxe = 200 + 5;

class Euler {
        int n, psz;
        struct Edge {
                int v, w;
                Edge *next;
        } epool[maxe], *e[maxn], *cur[maxn];
        int deg[maxn], vec[maxe], sz;
        bool vis[maxe];

        void dfs(int u)
        {
                while (cur[u]) {
                        Edge *i = cur[u]; cur[u] = cur[u]->next;
                        if (vis[abs(i->w)]) continue;
                        vis[abs(i->w)] = true;
                        dfs(i->v);
                        vec[sz++] = i->w;
                }
        }

        public:
        void init(int n)
        {
                this->n = n; psz = 0;
                memset(e, 0, sizeof(e));
                memset(deg, 0, sizeof(deg));
        }

        void add_edge(int u, int v, int w)
        {
                Edge *i = epool + psz++;
                i->v = v; i->w = w; i->next = e[u]; e[u] = i;
                if (psz & 1) add_edge(v, u, -w);
                else ++deg[u], ++deg[v];
        }

        bool find_path()
        {
                int s = -1, cs = 0;
                for (int i = 0; i < n; ++i) {
                        if (deg[i] && s == -1) s = i;
                        if (deg[i] & 1) s = i, ++cs;
                }
                if (cs && cs != 2) return false;
                sz = 0;
                memcpy(cur, e, sizeof(cur));
                memset(vis, false, sizeof(vis));
                dfs(s);
                if (sz < psz / 2) return false;
                reverse(vec, vec + sz);
                for (int i = 0; i < sz; ++i)
                        printf("%d %c\n", abs(vec[i]), vec[i] > 0? '+': '-');
                return true;
        }
} grp;

int main()
{
        grp.init(7);
        int m;
        scanf("%d", &m);
        For(i,1,m) {
                int u, v;
                scanf("%d%d", &u, &v);
                grp.add_edge(u, v, i);
        }
        if (!grp.find_path()) puts("No solution");

        return 0;
}

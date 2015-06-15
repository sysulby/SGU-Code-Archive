/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 134.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-06-14
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

const int maxn = 16000 + 5;

int n, psz;
struct Edge {
        int v;
        Edge *next;
} epool[maxn*2], *e[maxn];
int tot[maxn], val[maxn];

void add_edge(int u, int v)
{
        Edge *i = epool + psz++;
        i->v = v; i->next = e[u]; e[u] = i;
}

void dfs(int u, int f)
{
        tot[u] = 1;
        for (Edge *i = e[u]; i; i = i->next) {
                int v = i->v;
                if (v == f) continue;
                dfs(v, u);
                tot[u] += tot[v];
                val[u] = max(val[u], tot[v]);
        }
        val[u] = max(val[u], n - tot[u]);
}

int main()
{
        scanf("%d", &n);
        rep(i,n-1) {
                int u, v;
                scanf("%d%d", &u, &v);
                --u, --v;
                add_edge(u, v);
                add_edge(v, u);
        }
        dfs(0, -1);
        int ret = *min_element(val, val + n), cnt = 0;
        rep(i,n) if (val[i] == ret) ++cnt;
        printf("%d %d\n", ret, cnt);
        rep(i,n) if (val[i] == ret) printf("%d%c\n", i + 1, --cnt? ' ': '\n');

        return 0;
}

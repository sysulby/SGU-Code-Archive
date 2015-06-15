/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 121.cpp
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

const int maxn = 100 + 5;

int n, psz;
struct Edge {
        int v;
        Edge *next;
} epl[maxn*maxn], *e[maxn];
int deg[maxn];
int color[maxn][maxn];

void add_edge(int u, int v)
{
        Edge *i = epl + psz++;
        i->v = v; i->next = e[u]; e[u] = i;
        ++deg[u];
}

void dfs(int u, int c)
{
        for (Edge *i = e[u]; i; i = i->next) {
                int v = i->v;
                if (color[u][v]) continue;
                color[u][v] = color[v][u] = c;
                dfs(v, c = 3 - c);
        }
}

void print(int u, Edge *i)
{
        if (!i) return;
        print(u, i->next); printf("%d ", color[u][i->v]);
}

bool solve()
{
        rep(u,n) if (deg[u] != 2) dfs(u, 1);
        rep(u,n) dfs(u, 1);
        rep(u,n) {
                int c = 0;
                for (Edge *i = e[u]; i; i = i->next) c |= color[u][i->v];
                if (c != 3 && deg[u] > 1) return false;
        }
        rep(u,n) print(u, e[u]), puts("0");
        return true;
}

int main()
{
        scanf("%d", &n);
        rep(u,n) {
                int v;
                while (scanf("%d", &v) && v) add_edge(u, --v);
        }
        if (!solve()) puts("No solution");

        return 0;
}

/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 143.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-06-18
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
int val[maxn];

void add_edge(int u, int v)
{
        Edge *i = epool + psz++;
        i->v = v; i->next = e[u]; e[u] = i;
}

int dfs(int u, int f)
{
        int ret = -inf;
        for (Edge *i = e[u]; i; i = i->next) {
                int v = i->v;
                if (v == f) continue;
                ret = max(ret, dfs(v, u));
                if (val[v] > 0) val[u] += val[v];
        }
        return max(ret, val[u]);
}

int main()
{
        scanf("%d", &n);
        rep(i,n) scanf("%d", &val[i]);
        rep(i,n-1) {
                int u, v;
                scanf("%d%d", &u, &v);
                --u, --v;
                add_edge(u, v);
                add_edge(v, u);
        }
        printf("%d\n", dfs(0, -1));

        return 0;
}

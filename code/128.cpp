/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 128.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-06-13
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

const int maxn = 10000 + 5;

int n, sz;
int x[maxn], y[maxn], id[maxn];
struct Event {
        int x, t, y, l, r;
        Event() {}
        Event(int x, int t, int y): x(x), t(t), y(y) {}
        Event(int x, int t, int l, int r): x(x), t(t), l(l), r(r) {}
        bool operator<(const Event &e) const
        { return x ^ e.x? x < e.x: t < e.t; }
} vec[maxn*2];
multiset<int> st;
multiset<int>::iterator it;
bool vis[maxn];
map<int, Pii> adj[maxn];

int dfs(int u, int d, int dep)
{
        if (!adj[u].count(d)) return 0;
        vis[u] = true;
        int v = adj[u][d].first, w = adj[u][d].second;
        if (vis[v]) return dep == n - 1? w: 0;
        int ret = dfs(v, d ^ 1, dep + 1);
        return ret? ret + w: 0;
}

int cmpx(int a, int b) { return x[a] ^ x[b]? x[a] < x[b]: y[a] < y[b]; }
int cmpy(int a, int b) { return y[a] ^ y[b]? y[a] < y[b]: x[a] < x[b]; }
int solve()
{
        rep(i,n) id[i] = i;
        sort(id, id + n, cmpy);
        for (int i = 0, j; i < n; i = j) {
                for (j = i + 1; j < n && y[id[j]] == y[id[i]]; ++j);
                if ((j - i) & 1) return 0;
                for (int k = i; k < j; k += 2) {
                        int u = id[k], v = id[k+1];
                        adj[u][0] = Pii(v, x[v] - x[u]);
                        adj[v][0] = Pii(u, x[v] - x[u]);
                        vec[sz++] = Event(x[u], 1, y[u]);
                        vec[sz++] = Event(x[v], -1, y[v]);
                }
        }
        rep(i,n) id[i] = i;
        sort(id, id + n, cmpx);
        for (int i = 0, j; i < n; i = j) {
                for (j = i + 1; j < n && x[id[j]] == x[id[i]]; ++j);
                if ((j - i) & 1) return 0;
                for (int k = i; k < j; k += 2) {
                        int u = id[k], v = id[k+1];
                        adj[u][1] = Pii(v, y[v] - y[u]);
                        adj[v][1] = Pii(u, y[v] - y[u]);
                        vec[sz++] = Event(x[u], 0, y[u], y[v]);
                }
        }
        sort(vec, vec + sz);
        rep(i,sz) {
                if (vec[i].t < 0) st.erase(st.find(vec[i].y));
                if (vec[i].t > 0) st.insert(vec[i].y);
                if (!vec[i].t) {
                        it = st.upper_bound(vec[i].l);
                        if (it != st.end() && *it < vec[i].r) return 0;
                }
        }
        return dfs(0, 0, 0);
}

int main()
{
        scanf("%d", &n);
        rep(i,n) scanf("%d%d", &x[i], &y[i]);
        printf("%d\n", solve());

        return 0;
}

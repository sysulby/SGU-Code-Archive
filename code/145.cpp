/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 145.cpp
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

const int maxn = 100 + 5;

class Yen {
        struct Path {
                int w, dev;
                vector<int> v;
                bitset<maxn> blc;
                bool operator<(const Path &p) const { return w > p.w; }
        } p, q;
        int n, s, t, w[maxn][maxn];
        bitset<maxn> blc[maxn];
        int dis[maxn], pre[maxn];
        bool vis[maxn];

        bool dijkstra(Path &ret, int d = 0)
        {
                memset(pre, -1, sizeof(pre));
                memset(vis, false, sizeof(vis));
                memset(dis, 0x3f, sizeof(dis)); dis[s] = 0;
                for (int i = 0; i < d - 1; ++i) {
                        int u = p.v[i], v = p.v[i+1];
                        vis[u] = true; dis[v] = dis[u] + w[u][v], pre[v] = u;
                }
                for (int i = 0; i < n; ++i) {
                        int u = -1;
                        for (int v = 0; v < n; ++v) if (!vis[v])
                                if (u == -1 || dis[v] < dis[u]) u = v;
                        if (u == -1 || dis[u] == inf) break; vis[u] = true;
                        for (int v = 0; v < n; ++v) if (!vis[v]) {
                                if (blc[u][v] || blc[v][u]) continue;
                                if (dis[u] + w[u][v] < dis[v])
                                        dis[v] = dis[u] + w[u][v], pre[v] = u;
                        }
                }
                ret.w = dis[t]; ret.v.clear(); ret.blc.reset();
                for (int u = t; ~u; u = pre[u]) ret.v.push_back(u);
                reverse(ret.v.begin(), ret.v.end());
                return dis[t] != inf;
        }

        public:
        void init(int n)
        {
                this->n = n;
                memset(w, 0x3f, sizeof(w));
        }

        void add_edge(int u, int v, int w)
        {
                this->w[u][v] = this->w[v][u] = w;
        }

        bool find_kth(int src, int trg, int k)
        {
                s = src, t = trg;
                priority_queue<Path> que;
                for (int u = 0; u < n; ++u) blc[u].reset();
                if (!dijkstra(p)) return false;
                p.dev = 1; p.blc.set(p.v[1]); que.push(p);
                for (int i = 0; i < k; ++i) {
                        if (que.empty()) return false;
                        p = que.top(); que.pop();
                        for (int u = 0; u < n; ++u) blc[u].reset();
                        for (int d = p.dev; d < p.v.size(); ++d) {
                                int u = p.v[d-1];
                                d ^ p.dev? blc[u].set(p.v[d]): blc[u] = p.blc;
                                if (!dijkstra(q, d)) continue;
                                d ^ p.dev? q.blc.set(p.v[d]): q.blc = p.blc;
                                q.dev = d; q.blc.set(q.v[d]); que.push(q);
                        }
                }
                printf("%d %d\n", p.w, (int)p.v.size());
                for (int i = 0; i < p.v.size(); ++i)
                        printf("%d ", p.v[i] + 1);
                puts("");
                return true;
        }
} grp;

int main()
{
        int n, m, k, s, t;
        scanf("%d%d%d", &n, &m, &k);
        grp.init(n);
        while (m--) {
                int u, v, w;
                scanf("%d%d%d", &u, &v, &w);
                --u, --v;
                grp.add_edge(u, v, w);
                grp.add_edge(v, u, w);
        }
        scanf("%d%d", &s, &t);
        --s, --t;
        grp.find_kth(s, t, k);

        return 0;
}

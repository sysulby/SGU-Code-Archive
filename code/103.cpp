/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 103.cpp
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

const int maxn = 300 + 5;
const int maxe = 28000 + 5;

int psz;
struct Edge {
        int v, w;
        Edge *next;
} epl[maxe], *e[maxn];

void add_edge(int u, int v, int w)
{
        Edge *i = epl + psz++;
        i->v = v; i->w = w; i->next = e[u]; e[u] = i;
}

int n, m, s, t;
bool c[maxn];
int r[maxn], l[maxn][3];
int dis[maxn], pre[maxn];
bool inq[maxn];

int color(int u, int now)
{
        now = (now - r[u] + l[u][2]) % l[u][2];
        return now < l[u][c[u]^1]? c[u] ^ 1: c[u];
}

int calc(int u, int v, int now)
{
        For(i,now,now+300) if (color(u, i) == color(v, i)) return i;
        return inf;
}

void spfa()
{
        deque<int> deq;
        memset(dis, 0x3f, sizeof(dis));
        memset(inq, false, sizeof(inq));
        dis[s] = 0; inq[s] = true; deq.push_back(s);
        while (!deq.empty()) {
                int u = deq.front(); deq.pop_front(); inq[u] = false;
                for (Edge *i = e[u]; i; i = i->next) {
                        int v = i->v, w = calc(u, v, dis[u]) + i->w;
                        if (dis[v] <= w) continue;
                        dis[v] = w; pre[v] = u;
                        if (inq[v]) continue; inq[v] = true;
                        deq.empty() || dis[v] < dis[deq.front()]?
                                deq.push_front(v): deq.push_back(v);
                }
        }
}

void print(int u)
{
        if (u == s) { printf("%d", u + 1); return; }
        print(pre[u]); printf(" %d", u + 1);
}

int main()
{
        scanf("%d%d", &s, &t);
        --s; --t;
        scanf("%d%d", &n, &m);
        rep(i,n) {
                char buf[8];
                scanf("%s%d%d%d", buf, &r[i], &l[i][0], &l[i][1]);
                c[i] = (buf[0] == 'P');
                l[i][2] = l[i][0] + l[i][1];
        }
        while (m--) {
                int u, v, w;
                scanf("%d%d%d", &u, &v, &w);
                --u; --v;
                add_edge(u, v, w);
                add_edge(v, u, w);
        }
        spfa();
        if (dis[t] == inf) puts("0");
        else printf("%d\n", dis[t]), print(t), puts("");

        return 0;
}

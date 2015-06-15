/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 124.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-06-04
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

typedef complex<int> Point;
typedef complex<int> Vector;
#define X real()
#define Y imag()

int dot(Vector u, Vector v) { return u.X * v.X + u.Y * v.Y; }
int cross(Vector u, Vector v) { return u.X * v.Y - u.Y * v.X; }

typedef vector<Point> Polygon;

int in_polygon(Point p, const Polygon &g)
{
        int wn = 0;
        for (int i = 0, m = g.size(); i < m; ++i) {
                Point v1 = g[i] - p, v2 = g[(i+1)%m] - p;
                int c = cross(v1, v2), d = dot(v1, v2);
                if (!c && d <= 0) return 0;
                int d1 = v1.Y, d2 = v2.Y;
                if (c > 0 && d1 <= 0 && d2 > 0) ++wn;
                if (c < 0 && d2 <= 0 && d1 > 0) --wn;
        }
        return wn? 1: -1;
}


const int maxn = 10000 + 5;

int psz;
struct Edge {
        int v;
        Edge *next;
} epool[maxn*2], *e[maxn];

void add_edge(int u, int v)
{
        Edge *i = epool + psz++;
        i->v = v; i->next = e[u]; e[u] = i;
}

int n, tot;
Pii p[maxn*2];
map<Pii, int> mp;
bool vis[maxn*2];
Polygon g;

int get_id(Pii o)
{
        if (mp.count(o)) return mp[o];
        return p[tot] = o, mp[o] = tot++;
}

void dfs(int u, Polygon &g)
{
        vis[u] = true; g.push_back(Point(p[u].first, p[u].second));
        for (Edge *i = e[u]; i; i = i->next) {
                int v = i->v;
                if (!vis[v]) dfs(v, g);
        }
}

int main()
{
        int x, y;
        scanf("%d", &n);
        rep(i,n) {
                scanf("%d%d", &x, &y);
                int u = get_id(Pii(x, y));
                scanf("%d%d", &x, &y);
                int v = get_id(Pii(x, y));
                add_edge(u, v);
                add_edge(v, u);
        }
        dfs(0, g);
        scanf("%d%d", &x, &y);
        int res = in_polygon(Point(x, y), g);
        puts(res? res > 0? "INSIDE": "OUTSIDE": "BORDER");

        return 0;
}

/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 129.cpp
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

const double eps = 1e-8;
int sgn(double x) { return x < -eps? -1: x > eps; }

typedef complex<double> Point;
typedef complex<double> Vector;
#define X real()
#define Y imag()

double cross(Vector u, Vector v) { return u.X * v.Y - u.Y * v.X; }

typedef vector<Point> Polygon;

bool on_left(Point p, const Polygon &g)
{
        Point p1 = *++g.rbegin(), p2 = g.back();
        return sgn(cross(p2 - p1, p - p1)) <= 0;
}

bool cmp(Point a, Point b) { return sgn(a.X - b.X)? a.X < b.X: a.Y < b.Y; }

void convex_hull(Point p[], int n, Polygon &g)
{
        g.clear();
        sort(p, p + n, cmp);
        for (int i = 0; i < n; ++i) {
                while (g.size() > 1 && on_left(p[i], g)) g.pop_back();
                g.push_back(p[i]);
        }
        int k = g.size();
        for (int i = n - 2; i >= 0; --i) {
                while (g.size() > k && on_left(p[i], g)) g.pop_back();
                g.push_back(p[i]);
        }
        if (n > 1) g.pop_back();
}

const int maxn = 400 + 5;

int n, m;
Point p[maxn];
Polygon g;

double calc(Point s, Point t)
{
        Vector v = t - s;
        bool found = false;
        for (int i = 0, m = g.size(); i < m; ++i)
                if (sgn(cross(v, g[i] - s)) < 0) {
                        found = true; break;
                }
        if (!found) return 0;
        double ret = 0;
        for (int i = 0, m = g.size(); i < m; ++i) {
                Point v1 = g[i] - s, v2 = g[(i+1)%m] - s;
                double c1 = cross(v, v1), c2 = cross(v, v2);
                if (sgn(c1) <= 0 && sgn(c2) > 0) {
                        double c = cross(v, v2 - v1);
                        ret += max(min(cross(v2 - v1, s - g[i]) / c, 1.0), 0.0);
                }
                if (sgn(c1) > 0 && sgn(c2) <= 0) {
                        double c = cross(v, v2 - v1);
                        ret -= min(max(cross(v2 - v1, s - g[i]) / c, 0.0), 1.0);
                }
        }
        return ret * abs(v);
}

int main()
{
        int x, y;
        scanf("%d", &n);
        rep(i,n) {
                scanf("%d%d", &x, &y);
                p[i] = Point(x, y);
        }
        convex_hull(p, n, g);
        scanf("%d", &m);
        while (m--) {
                scanf("%d%d", &x, &y);
                Point s = Point(x, y);
                scanf("%d%d", &x, &y);
                Point t = Point(x, y);
                printf("%.10f\n", calc(s, t));
        }

        return 0;
}

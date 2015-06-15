/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 120.cpp
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

const double pi = acos(-1);

typedef complex<double> Point;
typedef complex<double> Vector;
#define X real()
#define Y imag()

Vector unit(Vector v) { return v / abs(v); }
Vector rotate(Vector v, double a) { return v * polar(1.0, a); }

const int maxn = 150 + 5;

int n, n1, n2;
Point p[maxn];

int main()
{
        scanf("%d%d%d", &n, &n1, &n2);
        --n1; --n2;
        double x, y;
        scanf("%lf%lf", &x, &y);
        p[n1] = Point(x, y);
        scanf("%lf%lf", &x, &y);
        p[n2] = Point(x, y);
        double a = (pi - 2 * pi / n * (n2 - n1)) / 2;
        double l = abs(p[n2] - p[n1]) / 2 / cos(a);
        Vector v = -rotate(unit(p[n2] - p[n1]) * l, -a);
        Point o = p[n1] - v;
        rep(i,n) {
                p[(n1+i)%n] = o + v;
                v = rotate(v, -2 * pi / n);
        }
        rep(i,n) printf("%.6f %.6f\n", p[i].X, p[i].Y);

        return 0;
}

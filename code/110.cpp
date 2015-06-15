/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 110.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-05-22
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

struct Point3 {
        double x, y, z;
        Point3(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {}
};
typedef Point3 Vector3;
Vector3 operator-(Vector3 v)
{ return Vector3(-v.x, -v.y, -v.z); }
Vector3 operator+(Vector3 u, Vector3 v)
{ return Vector3(u.x + v.x, u.y + v.y, u.z + v.z); }
Vector3 operator-(Vector3 u, Vector3 v)
{ return Vector3(u.x - v.x, u.y - v.y, u.z - v.z); }
Vector3 operator*(Vector3 u, double k)
{ return Vector3(u.x * k, u.y * k, u.z * k); }
Vector3 operator/(Vector3 u, double k)
{ return Vector3(u.x / k, u.y / k, u.z / k); }

double dot(Vector3 u, Vector3 v) { return u.x * v.x + u.y * v.y + u.z * v.z; }
double abs(Vector3 v) { return sqrt(dot(v, v)); }
Vector3 unit(Vector3 v) { return v / abs(v); }
Vector3 proj(Vector3 u, Vector3 v) { return v * dot(u, v) / dot(v, v); }
Vector3 reflect(Vector3 u, Vector3 v) { return proj(u, v) * 2.0 - u; }

const int maxn = 50 + 5;

int n;
Point3 c[maxn];
double r[maxn];
Point3 p;
Vector3 v;

void solve()
{
        rep(j,11) {
                Point3 t;
                int k = -1;
                rep(i,n) {
                        Point3 o = p + proj(c[i] - p, v);
                        double d = abs(o - c[i]);
                        if (sgn(d - r[i]) > 0) continue;
                        o = o - unit(v) * sqrt(r[i] * r[i] - d * d);
                        double dt = dot(o - p, v);
                        if (sgn(dt) <= 0) continue;
                        if (k == -1 || dt < dot(t - p, v)) t = o, k = i;
                }
                if (k == -1) { puts(""); return; }
                if (j == 10) { puts(" etc."); return; }
                p = t; v = reflect(-v, t - c[k]);
                printf("%s%d", j? " ": "", k + 1);
        }
}

int main()
{
        scanf("%d", &n);
        double x, y, z;
        rep(i,n) {
                scanf("%lf%lf%lf%lf", &x, &y, &z, &r[i]);
                c[i] = Point3(x, y, z);
        }
        scanf("%lf%lf%lf", &x, &y, &z);
        p = Point3(x, y, z);
        scanf("%lf%lf%lf", &x, &y, &z);
        v = Point3(x, y, z) - p;
        solve();

        return 0;
}

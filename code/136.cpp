/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 136.cpp
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

const double eps = 1e-8;
int sgn(double x) { return x < -eps? -1: x > eps; }

const int maxn = 10000 + 5;

int n;
double mx[maxn], my[maxn], x[maxn], y[maxn];

bool solve()
{
        if (n & 1) {
                x[0] = 0;
                rep(i,n) x[0] += (i & 1? -mx[i]: mx[i]) * 2;
                x[0] /= 2;
                rep(i,n-1) x[i+1] = mx[i] * 2 - x[i];
                y[0] = 0;
                rep(i,n) y[0] += (i & 1? -my[i]: my[i]) * 2;
                y[0] /= 2;
                rep(i,n-1) y[i+1] = my[i] * 2 - y[i];
        } else {
                x[0] = 0;
                rep(i,n-1) x[i+1] = mx[i] * 2 - x[i];
                if (sgn(x[n-1] + x[0] - mx[n-1] * 2)) return false;
                y[0] = 0;
                rep(i,n-1) y[i+1] = my[i] * 2 - y[i];
                if (sgn(y[n-1] + y[0] - my[n-1] * 2)) return false;
        }
        puts("YES");
        rep(i,n) printf("%.10f %.10f\n", x[i], y[i]);
        return true;
}

int main()
{
        scanf("%d", &n);
        rep(i,n) scanf("%lf%lf", &mx[i], &my[i]);
        if (!solve()) puts("NO");

        return 0;
}

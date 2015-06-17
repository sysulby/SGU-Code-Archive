/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 140.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-06-17
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

void gcd(int a, int b, int &g, int &x0, int &y0)
{
        if (!b) g = a, x0 = 1, y0 = 0;
        else gcd(b, a % b, g, y0, x0), y0 -= x0 * (a / b);
}

const int maxn = 100 + 5;

int n, p, b;
int a[maxn], x[maxn];

int main()
{
        scanf("%d%d%d", &n, &p, &b);
        a[0] = p;
        For(i,1,n) scanf("%d", &a[i]), a[i] %= p;
        for (int i = 0; i <= n; ++i) {
                int g, x0, y0;
                gcd(a[i], a[i-1], g, x0, y0);
                a[i] = g;
                x[i] = (x0 + p) % p;
                y0 = (y0 + p) % p;
                rep(j,i) x[j] = x[j] * y0 % p;
        }
        if (b % a[n]) {
                puts("NO");
        } else {
                puts("YES");
                b /= a[n];
                For(i,1,n) printf("%d%c", x[i] * b % p, " \n"[i==n]);
        }

        return 0;
}

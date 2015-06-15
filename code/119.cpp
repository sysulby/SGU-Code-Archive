/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 119.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-05-30
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

int inv(int a, int m)
{
        int g, x0, y0;
        gcd(a, m, g, x0, y0);
        return g == 1? (x0 + m) % m: -1;
}

vector<Pii> vec;

void solve(int a0, int b0, int n)
{
        rep(a,n) {
                int x = b0 * a % n;
                if (a0 % n == 0) {
                        if (x) continue;
                        rep(b,n) vec.push_back(Pii(a, b));
                } else {
                        int g = __gcd(a0, n);
                        if (x % g != 0) continue;
                        int b = inv(a0 / g, n / g) * (x / g) % (n / g);
                        while (b < n) vec.push_back(Pii(a, b)), b += n / g;
                }
        }
}

int main()
{
        int n, a0, b0;
        scanf("%d%d%d", &n, &a0, &b0);
        int g = __gcd(__gcd(a0, b0), n);
        solve(a0 / g, b0 / g, n / g);
        printf("%d\n", (int)vec.size());
        foreach(it,vec) printf("%d %d\n", it->first * g, it->second * g);

        return 0;
}

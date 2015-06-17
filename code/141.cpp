/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 141.cpp
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

void gcd(LL a, LL b, LL &g, LL &x0, LL &y0)
{
        if (!b) g = a, x0 = 1, y0 = 0;
        else gcd(b, a % b, g, y0, x0), y0 -= x0 * (a / b);
}

LL a, b, c, k;

bool calc(LL x, LL y)
{
        LL t = abs(x) + abs(y);
        if (t > k || ((k - t) & 1)) return false;
        puts("YES");
        k = (k - t) / 2;
        if (x >= 0) printf("%lld %lld ", x + k, k);
        else printf("%lld %lld ", k, -x + k);
        if (y >= 0) printf("%lld %lld\n", y, 0LL);
        else printf("%lld %lld\n", 0LL, -y);
        return true;
}

bool solve()
{
        LL g, x0, y0;
        gcd(a, b, g, x0, y0);
        if (c % g) return false;
        a /= g, b /= g, c /= g;
        For(t,-abs(c)-1,abs(c)+1)
                if (calc(x0 * c + b * t, y0 * c - a * t)) return true;
        return false;
}

int main()
{
        scanf("%lld%lld%lld%lld", &a, &b, &c, &k);
        if (!solve()) puts("NO");

        return 0;
}

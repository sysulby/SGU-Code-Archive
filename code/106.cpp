/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 106.cpp
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

void gcd(LL a, LL b, LL &g, LL &x0, LL &y0)
{
        if (!b) g = a, x0 = 1, y0 = 0;
        else gcd(b, a % b, g, y0, x0), y0 -= x0 * (a / b);
}


LL lower(LL k, LL b) { return b < 0? (-b + k - 1) / k: -b / k; }
LL upper(LL k, LL b) { return b > 0? -((b + k - 1) / k): -b / k; }

LL solve()
{
        int a, b, c, x1, y1, x2, y2;
        scanf("%d%d%d", &a, &b, &c); c = -c;
        scanf("%d%d", &x1, &x2);
        scanf("%d%d", &y1, &y2);
        if (x1 > x2 || y1 > y2) return 0;
        if (a == 0 && b == 0) {
                if (c) return 0;
                return (LL)(x2 - x1 + 1) * (y2 - y1 + 1);
        }
        if (a == 0) {
                if (c % b != 0 || c / b < y1 || c / b > y2) return 0;
                return x2 - x1 + 1;
        }
        if (b == 0) {
                if (c % a != 0 || c / a < x1 || c / a > x2) return 0;
                return y2 - y1 + 1;
        }
        LL g, x0, y0;
        gcd(a, b, g, x0, y0);
        if (c % g != 0) return 0;
        a /= g, b /= g; x0 *= c / g, y0 *= c / g;
        LL l = max(b > 0? lower(b, x0 - x1): lower(-b, x2 - x0),
                        a > 0? lower(a, y2 - y0): lower(-a, y0 - y1));
        LL r = min(b > 0? upper(b, x0 - x2): upper(-b, x1 - x0),
                        a > 0? upper(a, y1 - y0): upper(-a, y0 - y2));
        return l > r? 0: r - l + 1;
}

int main()
{
        cout << solve() << endl;

        return 0;
}

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

void gcd(int a, int b, int &g, int &x0, int &y0)
{
        if (!b) g = a, x0 = 1, y0 = 0;
        else gcd(b, a % b, g, y0, x0), y0 -= x0 * (a / b);
}

int a, b, c, k;

int calc(int x, int y)
{
        int t = abs(x) + abs(y);
        if (t > k) return 0;
        if ((k - t) & 1) return 1;
        k = (k - t) / 2;
        puts("YES");
        if (x < 0) printf("%d %d ", k, -x + k);
        else printf("%d %d ", x + k, k);
        if (y < 0) printf("%d %d\n", 0, -y);
        else printf("%d %d\n", y, 0);
        return 2;
}

int main()
{
        scanf("%d%d%d%d", &a, &b, &c, &k);
        int g, x0, y0;
        gcd(a, b, g, x0, y0);
        if (c % g) {
                puts("NO");
        } else {
                a /= g, b /= g, c /= g;
                int ret = calc(x0 * c, y0 * c);
                if (ret == 1)
                        ret = calc(x0 * c + b, y0 * c - a);
                if (ret != 2) puts("NO");
        }

        return 0;
}

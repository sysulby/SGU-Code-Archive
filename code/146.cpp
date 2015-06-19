/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 146.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-06-19
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

int main()
{
        double l;
        int n, len, ret = 0;
        scanf("%lf%d", &l, &n);
        len = l * 10000 + 0.5;
        rep(i,n) {
                int t, v;
                scanf("%d%d", &t, &v);
                ret = (ret + (LL)t * v * 10000) % len;
        }
        ret = min(ret, len - ret);
        printf("%d.%04d\n", ret / 10000, ret % 10000);

        return 0;
}

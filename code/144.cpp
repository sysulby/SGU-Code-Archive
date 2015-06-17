/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 144.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-06-18
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
        int x, y;
        double z;
        scanf("%d%d%lf", &x, &y, &z);
        double l = 60 * (y - x);
        double p = (l - z) / l;
        printf("%.7f\n", 1 - p * p);

        return 0;
}

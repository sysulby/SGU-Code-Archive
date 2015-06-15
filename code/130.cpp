/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 130.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-06-13
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
        int k;
        scanf("%d", &k);
        LL c = 1;
        For(i,1,k) c = c * (4 * i - 2) / (i + 1);
        printf("%lld %d\n", c, k + 1);

        return 0;
}

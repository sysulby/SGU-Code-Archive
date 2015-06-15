/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 102.cpp
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

int main()
{
        int n;
        scanf("%d", &n);
        int res = n;
        for (int i = 2; i * i <= n; ++i) if (n % i == 0) {
                res = res / i * (i - 1);
                while (n % i == 0) n /= i;
        }
        if (n != 1) res = res / n * (n - 1);
        printf("%d\n", res);

        return 0;
}

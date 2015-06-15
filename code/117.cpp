/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 117.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-05-23
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

int n, m, k;

int pow_mod(int a, int b)
{
        int res = 1;
        for (; b; a = a * a % k, b >>= 1) if (b & 1) res = res * a % k;
        return res;
}

int main()
{
        scanf("%d%d%d", &n, &m, &k);
        int res = 0;
        rep(i,n) {
                int x;
                scanf("%d", &x);
                if (!pow_mod(x % k, m)) ++res;
        }
        printf("%d\n", res);

        return 0;
}

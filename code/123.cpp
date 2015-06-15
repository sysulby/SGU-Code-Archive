/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 123.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-06-04
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

const int maxk = 41 + 5;

int k;
int f[maxk];

int main()
{
        scanf("%d", &k);
        f[0] = 0; f[1] = 1;
        int res = f[1];
        For(i,2,k) res += (f[i] = f[i-2] + f[i-1]);
        printf("%d\n", res);

        return 0;
}

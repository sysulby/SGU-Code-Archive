/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 135.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-06-14
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
        printf("%d\n", (n & 1? (n + 1) / 2 * n: n / 2 * (n + 1)) + 1);

        return 0;
}

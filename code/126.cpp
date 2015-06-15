/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 126.cpp
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

int dfs(int v, int n)
{
        if (!v) return 0;
        if (n & 1) return -1;
        int res = 0;
        while (v <= n / 2) ++res, v *= 2;
        int t = dfs((n - v) / 2, n / 2);
        return ~t? res + t: -1;
}

int main()
{
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", dfs(min(a, b), a + b));

        return 0;
}

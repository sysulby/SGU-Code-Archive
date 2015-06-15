/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 139.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-06-16
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

int g[4][4];

int main()
{
        rep(i,4) rep(j,4) scanf("%d", &g[i][j]);

        return 0;
}

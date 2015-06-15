/**
 * Copyright © 2014 Authors. All rights reserved.
 * 
 * FileName: 100.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2014-12-17
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
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", a + b);

        return 0;
}

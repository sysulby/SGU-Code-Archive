/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 115.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-05-22
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

int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
        int n, m;
        scanf("%d%d", &n, &m);
        if (n > a[m]) {
                puts("Impossible");
        } else {
                int now = n;
                rep(i,m) now += a[i];
                printf("%d\n", (6 + now) % 7 + 1);
        }

        return 0;
}

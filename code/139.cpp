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

int a[16];

int main()
{
        rep(i,16) scanf("%d", &a[i]);
        int cnt = 0;
        rep(i,16) {
                if (a[i]) {
                        rep(j,i) if (a[j] > a[i]) ++cnt;
                } else if (i & 4) {
                        ++cnt;
                }
        }
        puts(cnt & 1? "YES": "NO");

        return 0;
}

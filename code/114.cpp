/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 114.cpp
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

const int maxn = 15000 + 5;

int n;
Pii a[maxn];

int main()
{
        int tot = 0, now = 0;
        scanf("%d", &n);
        rep(i,n) {
                scanf("%d%d", &a[i].first, &a[i].second);
                tot += a[i].second;
        }
        sort(a, a + n);
        rep(i,n) if ((now += a[i].second) * 2 >= tot) {
                printf("%d.00000\n", a[i].first);
                break;
        }

        return 0;
}

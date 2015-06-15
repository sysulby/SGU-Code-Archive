/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 138.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-06-15
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

const int maxn = 100 + 5;

int n;
Pii a[maxn];
int pre[maxn];

int main()
{
        scanf("%d", &n);
        For(i,1,n) scanf("%d", &a[i].first), a[i].second = i;
        sort(a + 1, a + n + 1);
        For(i,1,n) pre[i] = pre[i-1] + a[i].first;
        int now = 0;
        for (int i = n; i >= 1; --i) {
                now += a[i].first - (i < n? 2: 0);
                if (now >= pre[i-1]) {
                        int c = (now - pre[i-1]) / 2;
                        a[0] = Pii(c, a[i].second);
                        a[i].first -= c;
                        break;
                }
        }
        printf("%d\n", pre[n] / 2);
        int l = 0, r = n;
        rep(i,pre[n]/2) {
                if (!--a[r].first) {
                        printf("%d %d\n", a[r-1].second, a[r].second);
                        --a[--r].first;
                } else {
                        if (!a[l].first) ++l;
                        printf("%d %d\n", a[r].second, a[l].second);
                        --a[l].first;
                }
        }

        return 0;
}

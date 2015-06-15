/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 127.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-06-05
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

const int maxn = 8000 + 5;

int k, n;
int a[maxn];

int main()
{
        scanf("%d%d", &k, &n);
        rep(i,n) scanf("%d", &a[i]);
        sort(a, a + n);
        int res = 2;
        for (int i = 0; i < n; ++i) {
                int j = i + 1, d = a[i] / 1000;
                while (j < n && a[j] / 1000 == d) ++j;
                res += (j - i + k - 1) / k;
                i = j - 1;
        }
        printf("%d\n", res);

        return 0;
}

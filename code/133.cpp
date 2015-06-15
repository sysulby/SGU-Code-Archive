/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 133.cpp
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

const int maxn = 16000 + 5;

int n;
Pii a[maxn];

int main()
{
        scanf("%d", &n);
        rep(i,n) scanf("%d%d", &a[i].second, &a[i].first);
        sort(a, a + n);
        stack<int> stc;
        rep(i,n) {
                while (!stc.empty() && a[i].second < stc.top()) stc.pop();
                stc.push(a[i].second);
        }
        printf("%d\n", n - (int)stc.size());

        return 0;
}

/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 108.cpp
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

const int maxv = 10000000 + 70;
const int maxk = 5000 + 5;

int n, k;
Pii s[maxk];
bitset<maxv> vis;

bool cmp(Pii a, Pii b) { return a.second < b.second; }

int main()
{
        scanf("%d%d", &n, &k);
        rep(i,k) scanf("%d", &s[i].first), s[i].second = i;
        sort(s, s + k);
        int tot = 0, now = 0;
        For(i,1,n) {
                if (!vis.test(i)) {
                        ++tot;
                        while (now < k && tot == s[now].first)
                                s[now++].first = i;
                }
                int t = i, v = i;
                while (t) v += t % 10, t /= 10;
                vis.set(v);
        }
        printf("%d\n", tot);
        sort(s, s + k, cmp);
        rep(i,k) printf("%d%c", s[i].first, i < k - 1? ' ': '\n');

        return 0;
}

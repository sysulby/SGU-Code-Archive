/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 113.cpp
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

const int maxv = 100000 + 5;

bool isp[maxv];
int prime[maxv], sz;
void gen_prime()
{
        sz = 0;
        memset(isp, true, sizeof(isp));
        isp[0] = isp[1] = false;
        for (int i = 2; i < maxv; ++i) {
                if (isp[i]) prime[sz++] = i;
                for (int j = 0, t; j < sz && (t = prime[j] * i) < maxv; ++j) {
                        isp[t] = false;
                        if (i % prime[j] == 0) break;
                }
        }
}

int main()
{
        gen_prime();
        int n, v;
        scanf("%d", &n);
        rep(i,n) {
                int t = 0;
                scanf("%d", &v);
                rep(j,sz) {
                        int p = prime[j];
                        if (p * p > v) break;
                        while (v % p == 0) ++t, v /= p;
                }
                if (v > 1) ++t;
                puts(t == 2? "Yes": "No");
        }

        return 0;
}

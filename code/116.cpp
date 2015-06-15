/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 116.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-05-23
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

const int maxv = 10000 + 5;

bool isp[maxv];
int prime[maxv], sz;
int a[maxv], m;
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
        for (int i = 0; prime[i] <= sz; ++i)
                a[m++] = prime[prime[i]-1];
}

int n;
int f[maxv], pre[maxv];

int main()
{
        gen_prime();
        scanf("%d", &n);
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        rep(i,m) For(j,a[i],n) if (f[j-a[i]] + 1 < f[j]) {
                f[j] = f[j-a[i]] + 1;
                pre[j] = i;
        }
        if (f[n] == inf) {
                puts("0");
        } else {
                printf("%d\n", f[n]);
                while (n) {
                        printf("%d", a[pre[n]]);
                        putchar((n -= a[pre[n]])? ' ': '\n');
                }
        }

        return 0;
}

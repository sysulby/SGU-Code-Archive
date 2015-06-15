/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 131.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-06-13
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

int n, m;
LL f[2][1<<9], g[1<<18];
int sp[6][2] = {{0, 3}, {1, 1}, {1, 3}, {2, 3}, {3, 1}, {3, 2}}, s[6];

LL solve()
{
        if (n > m) swap(n, m);
        if (n == 1) return ~m & 1;
        rep(k,6) s[k] = sp[k][1] << n | sp[k][0];
        int o = 0, half = (1 << n) - 1;
        For(S,0,half) {
                f[o][S] = 1;
                rep(i,n) if ((1 << i) & S) {
                        int k = i + 1;
                        while (k < n && ((1 << k) & S)) ++k;
                        if ((k - i) & 1) { f[o][S] = 0; break; }
                        i = k - 1;
                }
        }
        For(j,1,m-1) {
                o ^= 1;
                rep(S,1<<(n*2)) {
                        if (S <= half) { g[S] = f[o^1][S]; continue; }
                        g[S] = 0;
                        rep(i,n) if ((1 << (i + n)) & S) {
                                rep(k,6) if (k < 5 || i) {
                                        int S0 = s[k] << (k < 5? i: i - 1);
                                        if ((S0 & S) == S0) g[S] += g[S^S0];
                                }
                                break;
                        }
                }
                rep(S,1<<n) f[o][S] = g[S<<n|half];
        }
        return f[o][(1<<n)-1];
}

int main()
{
        scanf("%d%d", &n, &m);
        printf("%lld\n", solve());

        return 0;
}

/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 132.cpp
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

const int maxm = 70 + 5;

int m, n;
int s[maxm];
int f[2][1<<7][1<<7], g[1<<14];
int bits[1<<7];

bool check(int S)
{
        rep(i,n-1) if (((3 << i) & S) == (3 << i)) return false;
        return true;
}

int solve()
{
        int o = 0, half = (1 << n) - 1;
        memset(f[0], 0x3f, sizeof(f[0]));
        for (int S = s[0];; S = (S - 1) & s[0]) {
                f[o][S][0] = 0;
                rep(i,n) if ((1 << i) & S) {
                        if ((1 << ++i) & ~S) { f[o][S][0] = inf; break; }
                        ++f[o][S][0];
                }
                if (!S) break;
        }
        For(j,1,m-1) {
                o ^= 1;
                memset(g, 0x3f, sizeof(g));
                for (int S = s[j-1];; S = (S - 1) & s[j-1]) {
                        int R0 = (s[j-1] ^ S) & s[j];
                        for (int R = R0;; R = (R - 1) & R0) {
                                int S1 = S | R | R << n;
                                g[S1] = min(g[S1], f[o^1][S][R] + bits[R]);
                                if (!R) break;
                        }
                        if (!S) break;
                }
                int S0 = s[j] << n | s[j-1];
                rep(S,1<<(n*2)) if (S > half && (S & S0) == S) {
                        rep(i,n) if ((1 << (i + n)) & S) {
                                int S1 = 1 << (i + n);
                                if ((S1 >> n) & S)
                                        g[S] = min(g[S], g[S^S1^(S1>>n)] + 1);
                                if (i && ((S1 >> 1) & S))
                                        g[S] = min(g[S], g[S^S1^(S1>>1)] + 1);
                        }
                }
                memset(f[o], 0x3f, sizeof(f[o]));
                for (int S = S0;; S = (S - 1) & S0) {
                        int R = S0 ^ S;
                        if (g[S] != inf && check(R & half)) {
                                int &now = f[o][S>>n][(R&half)&(R>>n)];
                                now = min(now, g[S]);
                        }
                        if (!S) break;
                }
        }
        int ret = inf;
        for (int S = s[m-1];; S = (S - 1) & s[m-1]) {
                if (check(s[m-1] ^ S)) ret = min(ret, f[o][S][0]);
                if (!S) break;
        }
        return ret;
}

int main()
{
        rep(S,1<<7) bits[S] = (S? bits[S^(S&-S)] + 1: 0);
        scanf("%d%d", &m, &n);
        rep(j,m) {
                char buf[10];
                scanf("%s", buf);
                rep(i,n) s[j] = s[j] << 1 | (buf[i] == '.');
        }
        printf("%d\n", solve());

        return 0;
}

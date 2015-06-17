/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 142.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-06-17
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

const int maxn = 500000 + 5;
const int maxs = (1 << 20) + 5;

int n;
char s[maxn];

int main()
{
        scanf("%d%s", &n, s);
        For(i,1,n) {
                bitset<maxs> vis;
                int mask = (1 << i) - 1, S = 0;
                rep(j,i-1) S = S << 1 | (s[j] - 'a');
                for (int j = i - 1; j < n; ++j) {
                        S = (S << 1 | (s[j] - 'a')) & mask;
                        vis.set(S);
                }
                if (vis.count() < (1 << i)) {
                        printf("%d\n", i);
                        For(S,0,mask) if (!vis.test(S)) {
                                for (int j = i - 1; j >= 0; --j)
                                        putchar((1 << j) & S? 'b': 'a');
                                puts("");
                                break;
                        }
                        break;
                }
        }

        return 0;
}

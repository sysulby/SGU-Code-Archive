/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 104.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-05-21
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

int n, m;
int a[maxn][maxn];
int f[maxn][maxn], pre[maxn][maxn];

void print(int j, int i)
{
        if (pre[j][i] && i == 1) {
                printf("%d", j);
                return;
        }
        print(j - 1, i - pre[j][i]);
        if (pre[j][i]) printf(" %d", j);
}

int main()
{
        scanf("%d%d", &n, &m);
        For(i,1,n) For(j,1,m) scanf("%d", &a[i][j]);
        For(i,1,n) f[0][i] = -inf;
        For(j,1,m) For(i,1,n) {
                if (f[j-1][i] > f[j-1][i-1] + a[i][j])
                        f[j][i] = f[j-1][i], pre[j][i] = 0;
                else
                        f[j][i] = f[j-1][i-1] + a[i][j], pre[j][i] = 1;
        }
        printf("%d\n", f[m][n]);
        print(m, n); puts("");

        return 0;
}

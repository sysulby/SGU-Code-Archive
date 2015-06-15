/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 125.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-06-04
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

const int maxn = 3 + 5;

int n;
int a[maxn][maxn], b[maxn][maxn];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

bool inside(int x, int y) { return 0 <= x && x < n && 0 <= y && y < n; }

int calc(int x, int y)
{
        int c = 0;
        rep(i,4) {
                int nx = x + dx[i], ny = y + dy[i];
                if (inside(nx, ny) && a[nx][ny] > a[x][y]) ++c;
        }
        return c;
}

bool dfs(int i, int j)
{
        if (i == n && calc(n - 1, n - 1) == b[n-1][n-1]) return true;
        for (a[i][j] = 0; a[i][j] < 10; ++a[i][j]) {
                int c = 0;
                if (i && a[i-1][j] > a[i][j]) ++c;
                if (j && a[i][j-1] > a[i][j]) ++c;
                if (c > b[i][j]) continue;
                if (c + (i < n - 1? 2: 1) < b[i][j]) return false;
                if (i) {
                        c = calc(i - 1, j);
                        if (c < b[i-1][j]) continue;
                        if (c > b[i-1][j]) return false;
                }
                if (i == n - 1 && j) {
                        c = calc(i, j - 1);
                        if (c < b[i][j-1]) continue;
                        if (c > b[i][j-1]) return false;
                }
                if (dfs(i + (j + 1) / n, (j + 1) % n)) return true;
        }
        return false;
}

int main()
{
        scanf("%d", &n);
        rep(i,n) rep(j,n) scanf("%d", &b[i][j]);
        bool ok = true;
        rep(i,n) rep(j,n) {
                a[i][j] = -1;
                if (calc(i, j) < b[i][j]) ok = false;
                a[i][j] = 0;
        }
        if (ok && dfs(0, 0)) {
                rep(i,n) rep(j,n) printf("%d%c", a[i][j], " \n"[j==n-1]);
        } else {
                puts("NO SOLUTION");
        }

        return 0;
}

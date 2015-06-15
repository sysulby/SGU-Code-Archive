/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 107.cpp
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

const int val = 987654321;

int res[10], tot;
vector<int> vec;

void dfs(int d, int p)
{
        if (d == 10) return;
        int sz = vec.size();
        rep(i,sz) For(j,1,9) {
                int v = j * p + vec[i];
                LL t = (LL)v * v;
                if (t % 1000000000 == val) ++res[d], ++tot;
                if (t % (p * 10) == val % (p * 10)) vec.push_back(v);
        }
        dfs(d + 1, p * 10);
}

int main()
{
        int n;
        scanf("%d", &n);
        vec.push_back(0);
        dfs(1, 1);
        printf("%d", n < 10? res[n]: 9 * tot);
        rep(i,n-10) putchar('0'); puts("");

        return 0;
}

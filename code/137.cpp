/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 137.cpp
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

vector<int> dfs(int n, int k)
{
        vector<int> ret;
        int p = k / n; k %= n;
        if (k == 1) {
                rep(i,n-1) ret.push_back(p);
                ret.push_back(p + 1);
                return ret;
        }
        vector<int> d = dfs(k, n - k);
        for (int i = d.size() - 1; i >= 0; --i) {
                while (d[i]--) ret.push_back(p);
                ret.push_back(p + 1);
        }
        return ret;
}

int main()
{
        int n, k;
        scanf("%d%d", &n, &k);
        vector<int> ret = dfs(n, k);
        foreach(it,ret) printf("%d%c", *it, " \n"[it==--ret.end()]);

        return 0;
}

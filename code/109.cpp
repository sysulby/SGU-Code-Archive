/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 109.cpp
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

int main()
{
        int n;
        scanf("%d", &n);
        printf("%d", n * 2 + 1);
        For(i,1,n) For(j,1,n) if (~(i + j) & 1) {
                int v = (i - 1) * n + j;
                if (v != 1) printf(" %d", v);
        }
        puts("");
        printf("%d", n * 2 + 3);
        For(i,1,n) For(j,1,n) if ((i + j) & 1) {
                int v = (i - 1) * n + j;
                if (v != 1) printf(" %d", v);
        }
        puts("");

        return 0;
}

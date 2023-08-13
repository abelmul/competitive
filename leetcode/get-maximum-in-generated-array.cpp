#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int getMaximumGenerated(int n)
    {
        if (n <= 1) {
            return n;
        }

        vector<int> memo(n + 1);
        memo[1] = 1;

        int mx = 1;

        for (int i = 2; i <= n; ++i) {
            memo[i] = memo[i / 2];
            if (i % 2) {
                memo[i] += memo[i / 2 + 1];
            }
            mx = max(mx, memo[i]);
        }

        return mx;
    }
};

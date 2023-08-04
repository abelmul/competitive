#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int uniquePaths(int m, int n)
    {
        vector<vector<long long>> memo(m, vector<long long>(n));

        for (auto i = m - 1; i >= 0; --i) {
            for (auto j = n - 1; j >= 0; --j) {
                if (i + 1 >= m || j + 1 >= n) {
                    memo[i][j] = 1;
                } else {
                    memo[i][j] = memo[i + 1][j] + memo[i][j + 1];
                }
            }
        }

        return memo[0][0];
    }
};

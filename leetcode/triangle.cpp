#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        auto size = triangle.size();

        map<pair<int, int>, long long> memo;

        function<long long(int, int)> dp = [&](int i, int j) {
            if (i >= size)
                return (long long)0;

            if (memo.find({i, j}) == memo.end()) {
                memo[{i, j}] = triangle[i][j] + min(dp(i + 1, j), dp(i + 1, j + 1));
            }

            return memo[{i, j}];
        };

        return dp(0, 0);
    }
};

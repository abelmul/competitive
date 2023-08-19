#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int rows = nums.size();

        auto total = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> memo(rows, vector<int>(2 * total + 1, -1));

        function<int(int, int)> dp = [&](int i, int s) {
            if (i >= rows) {
                return static_cast<int>(s == target);
            }

            auto idx = total + s;

            if (memo[i][idx] == -1) {
                memo[i][idx] = dp(i + 1, s - nums[i]) + dp(i + 1, s + nums[i]);
            }

            return memo[i][idx];
        };

        return dp(0, 0);
    }
};

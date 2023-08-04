#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int combinationSum4(vector<int>& nums, int target)
    {
        int res = 0;

        vector<int> memo(target + 1, -1);

        function<int(int)> dp = [&](int amount) {
            if (amount <= 0) {
                return static_cast<int>(amount == 0);
            }

            if (memo[amount] == -1) {
                memo[amount] = 0;

                for (auto n : nums) {
                    memo[amount] += dp(amount - n);
                }
            }

            return memo[amount];
        };

        return dp(target);
    }
};

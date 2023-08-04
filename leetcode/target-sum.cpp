#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        auto size = nums.size();
        map<pair<int, int>, int> memo;

        function<int(int, int)> dp = [&](int i, int amount) {
            if (i >= size) {
                return static_cast<int>(amount == 0);
            }

            if (memo.find({i, amount}) == memo.end()) {
                memo[{i, amount}] = dp(i + 1, amount - nums[i]) + dp(i + 1, amount + nums[i]);
            }

            return memo[{i, amount}];
        };

        return dp(0, target);
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> memo(amount + 1);

        function<int(int)> dp = [&](int amount) {
            if (amount == 0)
                return 0;

            int res = INT_MAX;

            if (memo[amount] == 0) {
                for (auto c : coins) {
                    if (amount >= c) {
                        if (dp(amount - c) >= 0) {
                            res = min(res, 1 + dp(amount - c));
                        }
                    }
                }
                memo[amount] = res == INT_MAX ? -1 : res;
            }

            return memo[amount];
        };

        return dp(amount);
    }
};

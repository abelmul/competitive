#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<unsigned> memo(amount + 1, INT_MAX);

        memo[0] = 0;

        for (auto i = 1; i <= amount; ++i) {
            for (auto c : coins) {
                if (i >= c) {
                    memo[i] = min(memo[i], 1 + memo[i - c]);
                }
            }
        }

        return memo[amount] >= INT_MAX ? -1 : memo[amount];
    };
};

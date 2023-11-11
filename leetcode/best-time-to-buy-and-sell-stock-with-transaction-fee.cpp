#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int maxProfit(vector<int>& prices, int fee)
    {
        auto size = prices.size();
        vector<int> sell(size, INT_MIN), buy(size, INT_MIN);

        function<int(int, bool)> dp = [&](int i, bool to_sell) {
            vector<int>& memo = to_sell ? sell : buy;

            if (i >= size) {
                return 0;
            }

            if (memo[i] == INT_MIN) {
                int value = to_sell ? prices[i] - fee : -prices[i];

                memo[i] = max(dp(i + 1, to_sell), value + dp(i + 1, !to_sell));
            }

            return memo[i];
        };

        return dp(0, false);
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int maxProfit(vector<int>& prices)
    {
        int size = prices.size();

        int res = 0, r = 0;

        for (auto i = size - 1; i >= 0; --i) {
            r = max(r, prices[i]);
            res = max(res, r - prices[i]);
        }

        return res;
    }
};

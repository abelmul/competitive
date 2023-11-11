#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int findLongestChain(vector<vector<int>>& pairs)
    {
        auto size = pairs.size();
        vector<int> memo(size, -1);

        sort(pairs.begin(), pairs.end());

        function<int(int)> dp = [&](int l) {
            if (l >= size) {
                return 0;
            }

            if (memo[l] == -1) {
                memo[l] = 1;
                for (auto i = l + 1; i < size; ++i) {
                    memo[l] = max(memo[l], static_cast<int>(pairs[i][0] > pairs[l][1]) + dp(i));
                }
            }

            return memo[l];
        };

        return dp(0);
    }
};

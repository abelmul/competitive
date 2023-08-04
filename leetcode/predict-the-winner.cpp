#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool PredictTheWinner(vector<int>& nums)
    {
        auto size = nums.size();

        vector<vector<int>> memo(size, vector<int>(size));

        function<int(int, int)> canWin = [&](int l, int r) {
            if (l == r) {
                return nums[l];
            }

            if (memo[l][r] == 0) {
                memo[l][r] = max(nums[l] - canWin(l + 1, r), nums[r] - canWin(l, r - 1));
            }

            return memo[l][r];
        };

        return canWin(0, size - 1) >= 0;
    }
};

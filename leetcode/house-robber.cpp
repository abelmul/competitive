#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int rob(vector<int>& nums)
    {
        auto n = nums.size();

        if (n == 1)
            return nums[0];

        int first = nums[0];
        int second = max(first, nums[1]);
        int cur = second;

        for (auto i = 2; i < n; ++i) {
            cur = max(nums[i] + first, second);

            first = second;
            second = cur;
        }

        return second;
    }
};

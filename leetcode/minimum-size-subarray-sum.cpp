#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        auto size = nums.size();
        int len = INT_MAX;

        int l = 0, sum = 0;

        for (auto r = 0; r < size; ++r) {
            sum += nums[r];

            while (sum >= target) {
                len = min(len, r - l + 1);
                sum -= nums[l];
                ++l;
            }
        }

        return len == INT_MAX ? 0 : len;
    }
};

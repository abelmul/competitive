#include <bits/stdc++.h>

using namespace std;

class Solution
{
 private:
    inline int robNonCyclic(const vector<int>& nums, int begin, int end)
    {
        int first = nums[begin];
        int second = max(first, nums[begin + 1]);
        int cur = second;

        for (auto i = begin + 2; i < end; ++i) {
            cur = max(nums[i] + first, second);

            first = second;
            second = cur;
        }

        return cur;
    }

 public:
    int rob(vector<int>& nums)
    {
        auto n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        return max(robNonCyclic(nums, 0, n - 1), robNonCyclic(nums, 1, n));
    }
};

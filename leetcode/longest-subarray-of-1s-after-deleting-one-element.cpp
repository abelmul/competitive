#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int longestSubarray(vector<int>& nums)
    {
        auto size = nums.size();
        int res = 0;

        int l = 0;
        int no_of_zeros = 0;

        for (auto r = 0; r < size; ++r) {
            no_of_zeros += (nums[r] == 0);

            while (no_of_zeros > 1) {
                no_of_zeros -= (nums[l] == 0);
                ++l;
            }

            res = max(res, r - l);
        }

        return res;
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int search(vector<int>& nums, int target)
    {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            auto m = l + (r - l) / 2;

            if (nums[m] == target) {
                return m;
            }

            if (nums[m] >= nums[l]) {
                // ascending
                if (nums[l] <= target && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                // descending
                if (nums[r] >= target && target > nums[m]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }

        return -1;
    }
};

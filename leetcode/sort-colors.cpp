#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    void sortColors(vector<int>& nums)
    {
        // use count sort
        auto size = nums.size();
        int counter[] = {0, 0, 0};

        for (auto n : nums) {
            ++counter[n];
        }

        for (auto i = 0, j = 0; i < size; ++i) {
            while (counter[j] <= 0) {
                ++j;
            }
            nums[i] = j;
            --counter[j];
        }
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    void moveZeroes(vector<int>& nums)
    {
        size_t nums_size = nums.size();
        int last_input = nums_size;

        for (int i = 0; i < last_input; ++i) {
            if (nums[i] == 0) {
                for (int j = i; j < last_input - 1; ++j) {
                    swap(nums[j], nums[j + 1]);
                }
                nums[nums_size - 1] = 0;
                --last_input;
                --i;
            }
        }
    }
};

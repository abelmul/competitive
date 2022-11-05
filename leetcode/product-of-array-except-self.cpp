#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t nums_size = nums.size();
        int total_product = 1;
        int zero_count = 0;
        
        for(int num : nums) {
            if (num == 0) {
                ++zero_count;
                continue;
            }
            total_product *= num;
        }
        
        for(int i = 0; i < nums_size; ++i) {
            int answer = 0;
            if(nums[i] == 0 && zero_count == 1) {
                answer = total_product;
            } else if (zero_count == 0) {
                answer = total_product/nums[i];
            }
            nums[i] = answer;
        }
        
        return nums;
    }
};

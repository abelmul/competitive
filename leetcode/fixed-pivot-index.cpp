#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        size_t v_size =  nums.size();
        int total_sum = 0;
        
        for(int k : nums) {
            total_sum += k;
        }
        
        int left_sum = 0, right_sum = total_sum;
        
        for(int i = 0;  i < v_size; ++i) {
            right_sum -= nums[i];
            left_sum = total_sum - right_sum - nums[i];
            
            if (right_sum == left_sum)
                return i;
        }
        
        return -1;
    }
};

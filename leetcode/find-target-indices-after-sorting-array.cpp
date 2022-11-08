#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> answer;
        auto size = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < size; ++i) {
            if (nums[i] == target)
                answer.push_back(i);
            else if (nums[i] > target)
                break;
        }
        
        return answer;
    }
};

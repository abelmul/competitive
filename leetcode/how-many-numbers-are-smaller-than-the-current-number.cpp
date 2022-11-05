#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> answer;
        size_t nums_size = nums.size();
        
        for(int i : nums) {
            int min_count = 0;
            for(int j : nums){
                if(i > j)
                    ++min_count;
            }
            
            answer.push_back(min_count);
        }
        
        return answer;
    }
};

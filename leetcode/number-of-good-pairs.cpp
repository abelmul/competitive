#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int size = nums.size();
        int count = 0;
        
        for(int i = 1; i < size; ++i) {
            for(int j = 0; j < i; ++j) {
                if (nums[i] == nums[j]) {
                    ++count;
                }
            }
        }
        
        return count;
    }
};

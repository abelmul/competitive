#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 1)
            return;
        
        if (k > nums.size())
            k = k%nums.size();
        
        
        vector<int> answer = vector<int>(k);
        
        auto it = nums.end()-1;
        
        answer.insert(answer.begin() + k, nums.begin(), nums.end() - k);
        
        for(int i = k-1; i >= 0; --i) {
            answer[i] = *it;
            --it;
        }
        
        nums = answer;
    }
};

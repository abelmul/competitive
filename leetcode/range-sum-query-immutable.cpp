#include <bits/stdc++.h>

using namespace std;

class NumArray {
private:
    vector<int> data;
public:
    NumArray(vector<int>& nums) {
        auto data_size = nums.size();
        data = nums;
        
        for(int i = 1; i < data_size; ++i) {
            data[i] += data[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        int sub = left == 0 ? 0 : data[left-1];
        return data[right] - sub;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */


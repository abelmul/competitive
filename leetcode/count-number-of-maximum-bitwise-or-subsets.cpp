#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        auto size = nums.size();

        int max_bitwise = 0, res = 0;
        vector<int> cur;

        function<void(int, int, vector<int>&)> backtrack = [&](int l, int cur_bitwise, vector<int>& cur) {
            if (l >= size) {
                return;
            }

            for(auto i = l; i < size; ++i) {
                cur.push_back(nums[i]);

                if(max_bitwise == (cur_bitwise | nums[i])){
                    ++res;
                } else if(max_bitwise < (cur_bitwise | nums[i])) {
                    res = 1;
                    max_bitwise = (cur_bitwise | nums[i]);
                }

                backtrack(i+1, cur_bitwise | nums[i], cur);

                cur.pop_back();
            }
        };

        backtrack(0, 0, cur);

        return res;
    }
};

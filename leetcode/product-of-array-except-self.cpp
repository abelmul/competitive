#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int zeroCount = 0;
        int multiple = 1;

        vector<int> res;

        for (auto n : nums) {
            zeroCount += (n == 0);
            if (n != 0) {
                multiple *= n;
            }
        }

        if (zeroCount < 2) {
            for (auto n : nums) {
                if (zeroCount > 0 && n != 0) {
                    res.push_back(0);
                } else {
                    res.push_back(multiple / (n == 0 ? 1 : n));
                }
            }
        } else {
            res.resize(nums.size());
        }

        return res;
    }
};

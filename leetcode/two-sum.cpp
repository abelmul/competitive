#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> idxs;
        vector<int> res(2);

        for (auto i = 0; i < nums.size(); ++i) {
            if (idxs.find(target - nums[i]) != idxs.end()) {
                res[0] = idxs[target - nums[i]];
                res[1] = i;
                break;
            }
            idxs[nums[i]] = i;
        }

        return res;
    }
};

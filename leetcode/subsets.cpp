#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> cur;

        auto length = nums.size();

        function<void(int, vector<int>&)> backtrack = [&](int l, vector<int> cur) {
            res.push_back(cur);

            if (l >= length)
                return;

            for (auto i = l; i < length; ++i) {
                // take i
                cur.push_back(nums[i]);

                backtrack(i + 1, cur);

                cur.pop_back();
            }
        };

        backtrack(0, cur);

        return res;
    }
};

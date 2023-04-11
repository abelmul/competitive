#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        set<vector<int>> res;
        vector<int> cur;

        auto length = nums.size();

        sort(nums.begin(), nums.end());

        function<void(int, vector<int>&)> backtrack = [&](int l,
                                                          vector<int> cur) {
            res.insert(cur);

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

        return vector<vector<int>>(res.begin(), res.end());
    }
};

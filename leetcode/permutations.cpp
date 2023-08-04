#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> res;
        int size = nums.size();

        function<void(int, vector<int>&)> backtrack = [&](int l, vector<int>& cur) {
            if (l >= size) {
                res.push_back(cur);
                return;
            }

            for (auto i = l; i < size; ++i) {
                swap(cur[l], cur[i]);

                backtrack(l + 1, cur);

                swap(cur[l], cur[i]);
            }
        };

        backtrack(0, nums);

        return res;
    }
};

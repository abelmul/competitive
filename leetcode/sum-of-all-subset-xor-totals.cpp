#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int subsetXORSum(vector<int>& nums)
    {
        auto size = nums.size();
        int res = 0;

        vector<int> cur;

        function<void(int, vector<int>&)> backtrack = [&](int l, vector<int>& cur) {
            int x = 0;
            for (auto c : cur) x ^= c;

            res += x;

            if (l >= size)
                return;

            for (auto i = l; i < size; ++i) {
                cur.push_back(nums[i]);
                backtrack(i + 1, cur);
                cur.pop_back();
            }
        };

        backtrack(0, cur);
        return res;
    }
};

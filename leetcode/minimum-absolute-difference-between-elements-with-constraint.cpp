#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int minAbsoluteDifference(vector<int>& nums, int x)
    {
        int res = INT_MAX;

        auto size = nums.size();
        multiset<int> s;

        for (auto i = x; i < size; ++i) {
            s.insert(nums[i - x]);
            auto it = s.upper_bound(nums[i]);

            if (it != s.end()) {
                res = min(res, abs(nums[i] - *it));
            }

            if (it != s.begin()) {
                res = min(res, abs(nums[i] - *prev(it)));
            }
        }

        return res;
    }
};

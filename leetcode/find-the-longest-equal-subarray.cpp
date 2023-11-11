#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int longestEqualSubarray(vector<int>& nums, int k)
    {
        int res = 0;

        auto size = nums.size();
        int l = 0;
        unordered_map<int, int> counter;
        int max_freq = 0;

        for (auto i = 0; i < size; ++i) {
            ++counter[nums[i]];
            max_freq = max(max_freq, counter[nums[i]]);

            while (i - max_freq - l + 1 > k) {
                --counter[nums[l]];
                max_freq = max(max_freq, counter[nums[i]]);
                ++l;
            }

            res = max(res, max_freq);
        }

        return res;
    }
};

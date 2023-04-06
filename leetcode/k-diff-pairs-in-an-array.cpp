#include <bits/stdc++.h>
using namespace std;

class Solution
{
 public:
    int hasKDiffPair(vector<int>& nums, int i, int k)
    {
        auto l = i + 1;
        auto r = nums.size();
        int m;

        while (l < r) {
            m = l + (r - l) / 2;

            if (nums[m] - nums[i] >= k) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

    int findPairs(vector<int>& nums, int k)
    {
        int idx, length = nums.size();
        unordered_map<int, int> unique_pairs;

        sort(nums.begin(), nums.end());

        for (auto i = 0; i < length; ++i) {
            idx = hasKDiffPair(nums, i, k);
            if (idx < nums.size() && nums[idx] - nums[i] == k) {
                unique_pairs[nums[i]] = nums[idx];
            }
        }

        return unique_pairs.size();
    }
};

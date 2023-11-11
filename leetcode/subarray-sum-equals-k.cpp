#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int subarraySum(vector<int>& nums, int k)
    {
        auto size = nums.size();

        int res = 0;
        long long total = 0;
        unordered_map<long long, int> presum_map;

        presum_map[0] = 1;

        for (auto i = 0; i < size; ++i) {
            total += nums[i];

            if (presum_map.find(total - k) != presum_map.end()) {
                res += presum_map[total - k];
            }

            ++presum_map[total];
        }

        return res;
    }
};

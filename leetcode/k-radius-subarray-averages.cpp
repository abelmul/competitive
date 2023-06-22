#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<int> getAverages(vector<int>& nums, int k)
    {
        const auto diameter = 2 * k + 1;
        auto size = nums.size();
        vector<long long> presum(size + 1);

        vector<int> res;

        for (auto i = 0; i < size; ++i) {
            presum[i + 1] = presum[i] + nums[i];
        }

        for (auto i = 0; i < size; ++i) {
            if (i - k < 0 || i + k >= size) {
                res.push_back(-1);
            } else {
                res.push_back((presum[i + k + 1] - presum[i - k]) / diameter);
            }
        }

        return res;
    }
};

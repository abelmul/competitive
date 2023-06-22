#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    long long maxStrength(vector<int>& nums)
    {
        bool found = false;
        long long res = 1;

        auto n = nums.size();

        sort(nums.rbegin(), nums.rend());

        for (auto i = 0; i < n && nums[i] > 0; ++i) {
            res *= nums[i];
            found = true;
        }

        for (int j = n - 1; j - 1 >= 0 && nums[j] < 0 && nums[j - 1] < 0; j -= 2) {
            res *= nums[j];
            res *= nums[j - 1];
            found = true;
        }

        return found
                   ? res
                   : accumulate(nums.begin(), nums.end(), 1, [](auto a, auto b) { return a * b; });
    }
};

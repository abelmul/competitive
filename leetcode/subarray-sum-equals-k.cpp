#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int subarraySum(vector<int>& nums, int k)
    {
        int size = nums.size();
        unordered_map<int, int> prev_sum;
        int current_sum = 0;
        int count = 0;

        for (int i = 0; i < size; ++i) {
            current_sum += nums[i];

            if (current_sum == k)
                ++count;
            if (prev_sum.find(current_sum - k) != prev_sum.end())
                count += prev_sum[current_sum - k];

            prev_sum[current_sum]++;
        }
        return count;
    }
};

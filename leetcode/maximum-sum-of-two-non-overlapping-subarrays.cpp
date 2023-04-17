#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int get_max(vector<int>& prefix_sum, int firstLen, int secondLen)
    {
        auto size = prefix_sum.size();
        int max_sum = prefix_sum[firstLen + secondLen - 1];
        int first_max = prefix_sum[firstLen - 1];

        for (int i = 0; i < size - firstLen - secondLen; i++) {
            int sum1 = prefix_sum[i + firstLen] - prefix_sum[i];
            int second_max = prefix_sum[i + firstLen + secondLen] - prefix_sum[i + firstLen];
            first_max = max(first_max, sum1);
            max_sum = max(max_sum, first_max + second_max);
        }

        return max_sum;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen)
    {
        auto size = nums.size();
        vector<int> prefix_sum = vector<int>(size);

        prefix_sum[0] = nums[0];
        for (int i = 1; i < size; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }

        return max(get_max(prefix_sum, firstLen, secondLen),
                   get_max(prefix_sum, secondLen, firstLen));
    }
};

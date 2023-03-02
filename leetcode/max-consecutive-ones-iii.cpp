#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int longestOnes(vector<int>& nums, int k)
    {
        int i = 0;
        int current_max = 0;
        auto size = nums.size();
        size_t zeros_size;
        vector<int> zeros = {-1};

        for (int i = 0; i < size; ++i) {
            if (nums[i] == 0)
                zeros.push_back(i);
        }
        zeros.push_back(size);

        zeros_size = zeros.size();

        if (k > zeros_size - 2)
            return size;

        int start = 0;
        int end = k + 1;

        while (end < zeros_size) {
            current_max = max(current_max, zeros[end] - zeros[start] - 1);
            ++end;
            ++start;
        }

        return current_max;
    }
};

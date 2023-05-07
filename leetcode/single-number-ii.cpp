#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int singleNumber(vector<int>& nums)
    {
        int res = 0;
        int count[32] = {0};

        for (auto n : nums) {
            for (auto i = 0; i < 32; ++i) {
                if (n & (1 << i))
                    ++count[i];
            }
        }

        for (auto i = 0; i < 32; ++i) {
            if (count[i] % 3 == 1) {
                res = res | (1 << i);
            }
        }

        return res;
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool doesValidArrayExist(vector<int>& derived)
    {
        int xor_sum = 0;
        for (auto n : derived) {
            xor_sum ^= n;
        }

        return xor_sum == 0;
    }
};

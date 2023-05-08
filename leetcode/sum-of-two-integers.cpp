#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int getSum(int a, int b)
    {
        int sum = 0;
        int carry = 0;

        int i;

        for (i = 0; i < 32; ++i) {
            auto s = (a & 1) + (b & 1) + carry;

            carry = s > 1;
            sum = sum | ((s % 2) << i);

            a >>= 1;
            b >>= 1;
        }

        return sum;
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int bitwiseComplement(int n)
    {
        if (n == 0)
            return 1;

        int res = 0, i = 0;

        while (n) {
            res = res | (!(n & 1) << i);
            n >>= 1;
            ++i;
        }

        return res;
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int findComplement(int num)
    {
        int res = 0, i = 0;

        while (num) {
            res = res | (!(num & 1) << i);
            num >>= 1;
            ++i;
        }

        return res;
    }
};

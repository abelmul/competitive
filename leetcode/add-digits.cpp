#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int addDigits(int num)
    {
        int res = 0;

        while (num != 0) {
            res += num % 10;
            num = num / 10;
        }

        if (res < 10)
            return res;

        return addDigits(res);
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    string removeTrailingZeros(string num)
    {
        auto size = num.size();
        int r;

        for (r = size - 1; r >= 0 && num[r] == '0'; --r)
            ;

        return num.substr(0, r + 1);
    }
};

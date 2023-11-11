#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    string convertToTitle(int columnNumber)
    {
        string res;

        while (columnNumber >= 1) {
            --columnNumber;
            res += 'A' + columnNumber % 26;
            columnNumber /= 26;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

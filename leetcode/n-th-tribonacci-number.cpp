#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int tribonacci(int n)
    {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 1;
        }

        // bottom up
        int TN = 0, TN1 = 1, TN2 = 1, res;
        for (auto i = 3; i <= n; ++i) {
            res = TN2 + TN1 + TN;

            TN = TN1;
            TN1 = TN2;
            TN2 = res;
        }

        return res;
    }
};

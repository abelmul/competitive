#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n == 1 || x == 0 || x == 1)
            return x;

        auto negative = n < 0;

        n = abs(n);

        double ans = myPow(x, n / 2);
        ans *= ans;

        if (n % 2 == 1) {
            ans *= x;
        }

        return negative ? 1 / ans : ans;
    }
};

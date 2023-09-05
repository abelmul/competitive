#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int bestClosingTime(string customers)
    {
        auto size = customers.size();
        int sum = 0, maxSum = 0;
        int res = 0;

        for (auto i = 1; i < size + 1; ++i) {
            sum = sum + (customers[i - 1] == 'Y' ? 1 : -1);
            if (sum > maxSum) {
                maxSum = sum;
                res = i;
            }
        }

        return res;
    }
};

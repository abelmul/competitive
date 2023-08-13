#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int size = cost.size();

        int one_step = 0, two_step = 0;
        int res;

        for (auto i = size - 1; i >= 0; --i) {
            res = cost[i] + min(one_step, two_step);
            two_step = one_step;
            one_step = res;
        }

        return min(one_step, two_step);
    }
};

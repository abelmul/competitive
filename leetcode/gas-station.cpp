#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        auto n = gas.size();

        int res = 0;
        int total = 0, sum = 0;

        for (auto i = 0; i < n; ++i) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];

            if (total < 0) {
                res = i + 1;
                total = 0;
            }
        }

        return sum >= 0 ? res : -1;
    }
};

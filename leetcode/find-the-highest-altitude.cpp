#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int largestAltitude(vector<int>& gain)
    {
        int res = 0, s = 0;
        for (auto g : gain) {
            s += g;
            res = max(res, s);
        }

        return res;
    }
};

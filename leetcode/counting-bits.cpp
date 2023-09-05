#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<int> countBits(int n)
    {
        vector<int> res(n + 1);

        for (auto i = 1; i <= n; ++i) {
            // Brian Kernighan’s Algorithm
            res[i] = 1 + res[i & (i - 1)];
        }

        return res;
    }
};

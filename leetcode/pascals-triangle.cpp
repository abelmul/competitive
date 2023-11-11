#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        vector<int> cur;

        res.push_back({1});

        for (auto i = 1; i < numRows; ++i) {
            cur.resize(i + 1);
            cur[0] = 1;
            for (auto j = 1; j < i; ++j) {
                cur[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            cur[i] = 1;

            res.push_back(cur);
        }

        return res;
    }
};

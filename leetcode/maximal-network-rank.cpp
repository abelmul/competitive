#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads)
    {
        vector<set<int>> adjlist(n);
        int res = 0;

        for (auto r : roads) {
            adjlist[r[0]].insert(r[1]);
            adjlist[r[1]].insert(r[0]);
        }

        for (auto i = 0; i < n; ++i) {
            for (auto j = i + 1; j < n; ++j) {
                res = max(res, (int)(adjlist[i].size() + adjlist[j].size() -
                                     (adjlist[i].find(j) != adjlist[i].end())));
            }
        }

        return res;
    }
};

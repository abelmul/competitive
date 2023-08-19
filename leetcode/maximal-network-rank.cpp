#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads)
    {
        unordered_map<int, unordered_set<int>> adjList;
        int res = 0;

        for (auto r : roads) {
            adjList[r[0]].insert(r[1]);
            adjList[r[1]].insert(r[0]);
        }

        for (auto i = 0; i < n; ++i) {
            for (auto j = i + 1; j < n; ++j) {
                bool hasDirectConnection = adjList[i].find(j) != adjList[i].end();

                res = max(res, static_cast<int>(adjList[i].size() + adjList[j].size() -
                                                hasDirectConnection));
            }
        }

        return res;
    }
};

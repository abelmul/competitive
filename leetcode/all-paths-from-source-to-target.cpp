#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        auto n = graph.size();

        vector<vector<int>> adjList(graph.size());
        vector<vector<int>> res;

        for (auto i = 0; i < n; ++i) {
            for (auto j : graph[i]) {
                adjList[i].push_back(j);
            }
        }

        function<void(vector<int>, int)> backtrack = [&](vector<int> prev, int i) {
            if (i == n - 1) {
                prev.push_back(n - 1);
                res.push_back(prev);
                return;
            }

            prev.push_back(i);

            for (auto j : adjList[i]) {
                backtrack(prev, j);
            }
        };

        backtrack({}, 0);

        return res;
    }
};

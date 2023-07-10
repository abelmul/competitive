#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        vector<int> res, indegree(n);
        vector<pair<int, int>> sorted;
        unordered_map<int, vector<int>> adjList;

        deque<pair<int, int>> queue;
        int last_level;

        for (auto e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);

            ++indegree[e[0]];
            ++indegree[e[1]];
        }

        for (auto i = 0; i < n; ++i) {
            if (indegree[i] <= 1) {
                queue.emplace_back(i, 0);
            }
        }

        sorted.reserve(n);
        while (!queue.empty()) {
            auto t = queue.front();
            queue.pop_front();

            sorted.push_back(t);

            for (auto i : adjList[t.first]) {
                --indegree[i];

                if (indegree[i] == 1) {
                    queue.emplace_back(i, t.second + 1);
                }
            }
        }

        last_level = sorted.back().second;
        while (!sorted.empty() && last_level == sorted.back().second) {
            res.push_back(sorted.back().first);
            sorted.pop_back();
        }

        return res;
    }
};

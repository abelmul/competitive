#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        auto size = graph.size();

        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(size);
        deque<int> queue;
        int i;

        vector<int> res;

        for (auto i = 0; i < size; ++i) {
            indegree[i] += graph[i].size();
            for (auto v : graph[i]) {
                adjList[v].push_back(i);
            }
        }

        for (auto i = 0; i < size; ++i) {
            if (indegree[i] == 0) {
                queue.push_back(i);
            }
        }

        while (!queue.empty()) {
            i = queue.front();
            queue.pop_front();

            res.push_back(i);

            for (auto j : adjList[i]) {
                --indegree[j];
                if (indegree[j] == 0) {
                    queue.push_back(j);
                }
            }
        }

        sort(res.begin(), res.end());

        return res;
    }
};

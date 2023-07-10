#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs)
    {
        auto n = adjacentPairs.size() + 1;

        int current;
        vector<int> res;
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, int> indegree;
        deque<int> queue;

        for (auto e : adjacentPairs) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
            ++indegree[e[0]];
            ++indegree[e[1]];
        }

        res.reserve(n);
        for (auto& [k, v] : indegree) {
            if (v == 1) {
                queue.push_back(k);
                break;
            }
        }

        // topo sort
        while (!queue.empty()) {
            auto t = queue.front();
            queue.pop_back();

            --indegree[t];
            res.push_back(t);

            for (auto i : adjList[t]) {
                --indegree[i];
                // 0 happens if the element is the last one
                if (indegree[i] == 1 || indegree[i] == 0) {
                    queue.push_back(i);
                }
            }
        }

        return res;
    }
};

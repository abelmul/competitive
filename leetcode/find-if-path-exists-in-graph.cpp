#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        deque<int> queue;
        unordered_set<int> visited;

        unordered_map<int, vector<int>> graph;

        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        queue.push_back(source);

        while (!queue.empty()) {
            int node = queue.front();
            queue.pop_front();

            if (visited.find(node) != visited.end())
                continue;

            visited.insert(node);

            if (node == destination)
                return true;

            for (auto e : graph[node]) {
                queue.push_back(e);
            }
        }

        return false;
    }
};

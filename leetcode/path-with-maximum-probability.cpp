#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb,
                          int start_node, int end_node)
    {
        vector<vector<pair<int, double>>> adjList(n);

        priority_queue<pair<double, int>> pq;
        vector<double> res(n, 0);

        double prob, node;

        for (auto i = 0; i < edges.size(); ++i) {
            adjList[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            adjList[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }

        pq.emplace(1, start_node);

        while (!pq.empty()) {
            tie(prob, node) = pq.top();
            pq.pop();

            if (res[node] > 0) {
                continue;
            }

            res[node] = prob;

            for (auto n : adjList[node]) {
                pq.emplace(prob * n.second, n.first);
            }
        }

        return res[end_node];
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<int> dist(n, INT_MAX);
        int res = 0;

        int node, weight;

        vector<vector<pair<int, int>>> adjList(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto t : times) {
            adjList[t[0] - 1].emplace_back(t[1], t[2]);
        }

        pq.emplace(0, k);

        while (!pq.empty()) {
            tie(weight, node) = pq.top();

            pq.pop();

            if (dist[node - 1] != INT_MAX)
                continue;

            dist[node - 1] = weight;

            for (auto n : adjList[node - 1]) {
                pq.emplace(weight + n.second, n.first);
            }
        }

        for (auto d : dist) {
            res = max(res, d);
        }

        return res == INT_MAX ? -1 : res;
    }
};

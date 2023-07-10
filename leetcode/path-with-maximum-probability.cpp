#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start,
                          int end)
    {
        auto size = edges.size();
        unordered_map<int, vector<pair<int, double>>> adjLIst;
        priority_queue<pair<double, int>> pq;

        unordered_set<int> visited;

        for (auto i = 0; i < size; ++i) {
            adjLIst[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            adjLIst[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }

        pq.emplace(1, start);

        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();

            if (visited.find(t.second) != visited.end())
                continue;

            visited.insert(t.second);

            if (t.second == end) {
                return t.first;
            }

            for (auto n : adjLIst[t.second]) {
                pq.emplace(t.first * n.second, n.first);
            }
        }

        return 0;
    }
};

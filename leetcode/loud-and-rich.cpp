#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet)
    {
        auto n = quiet.size();

        vector<int> res(n), indegree(n);
        unordered_map<int, vector<int>> adjList;
        deque<int> queue;
        int t;

        for (auto r : richer) {
            adjList[r[0]].push_back(r[1]);
            ++indegree[r[1]];
        }

        for (auto i = 0; i < n; ++i) {
            res[i] = i;
            if (indegree[i] == 0) {
                queue.push_back(i);
            }
        }

        while (!queue.empty()) {
            t = queue.front();
            queue.pop_front();

            for (auto i : adjList[t]) {
                --indegree[i];

                if (quiet[res[t]] < quiet[res[i]]) {
                    res[i] = res[t];
                }

                if (indegree[i] == 0) {
                    queue.push_back(i);
                }
            }
        }

        return res;
    }
};

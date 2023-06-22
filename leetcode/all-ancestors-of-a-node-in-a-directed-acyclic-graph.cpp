#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges)
    {
        unordered_map<int, vector<int>> adjList;
        deque<int> queue;
        vector<int> indegree(n);
        int i;

        vector<set<int>> res_set(n);
        vector<vector<int>> res;

        for (auto e : edges) {
            adjList[e[0]].push_back(e[1]);
            ++indegree[e[1]];
        }

        for (i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                queue.push_back(i);
            }
        }

        while (!queue.empty()) {
            i = queue.front();
            queue.pop_front();

            for (auto j : adjList[i]) {
                --indegree[j];
                for (auto k : res_set[i]) {
                    res_set[j].insert(k);
                }
                res_set[j].insert(i);
                if (indegree[j] == 0) {
                    queue.push_back(j);
                }
            }
        }

        for (auto r : res_set) {
            res.push_back(vector<int>(r.begin(), r.end()));
        }

        return res;
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        unordered_map<int, vector<int>> graph;

        for (auto i = 0; i < n; ++i) {
            if (manager[i] >= 0) {
                graph[manager[i]].push_back(i);
            }
        }

        function<int(int)> dfs = [&](int i) {
            int res = informTime[i];
            int max_subordinate = 0;

            for (auto s : graph[i]) {
                max_subordinate = max(max_subordinate, dfs(s));
            }

            return res + max_subordinate;
        };

        return dfs(headID);
    }
};

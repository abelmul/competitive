#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int res = 0;
        auto n = isConnected.size();

        unordered_set<int> visited;

        function<void(int, unordered_set<int>&)> dfs = [&](int i, unordered_set<int>& visited) {
            if (visited.find(i) != visited.end())
                return;

            visited.insert(i);

            for (auto j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    dfs(j, visited);
                }
            }
        };

        for (auto i = 0; i < n; ++i) {
            if (visited.find(i) == visited.end()) {
                dfs(i, visited);
                ++res;
            }
        }

        return res;
    }
};

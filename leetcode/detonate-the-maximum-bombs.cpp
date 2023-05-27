#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int dfs(const vector<vector<int>>& adjList, int i)
    {
        int res = 0;

        stack<int> st;
        unordered_set<int> visited;

        st.push(i);

        while (!st.empty()) {
            i = st.top();
            st.pop();

            if (visited.find(i) != visited.end())
                continue;

            visited.insert(i);
            ++res;

            for (auto j : adjList[i]) {
                st.push(j);
            }
        }

        return res;
    }

    int maximumDetonation(vector<vector<int>>& bombs)
    {
        auto n = bombs.size();
        int res;

        vector<vector<int>> adjList(n);

        long long x1, y1, r1;

        for (auto i = 0; i < n; ++i) {
            x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];

            for (auto j = 0; j < n; ++j) {
                if ((x1 - bombs[j][0]) * (x1 - bombs[j][0]) +
                        (y1 - bombs[j][1]) * (y1 - bombs[j][1]) <=
                    r1 * r1) {
                    adjList[i].push_back(j);
                }
            }
        }

        for (auto i = 0; i < n; ++i) {
            res = max(res, dfs(adjList, i));
        }

        return res;
    }
};

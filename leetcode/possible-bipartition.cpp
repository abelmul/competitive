#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool dfs(unordered_map<int, vector<int>>& adjList, vector<int>& colors, int i)
    {
        for (auto j : adjList[i]) {
            if (colors[j - 1] == -1) {
                colors[j - 1] = !colors[i - 1];
                if (!dfs(adjList, colors, j)) {
                    return false;
                }
            } else if (colors[j - 1] != !colors[i - 1]) {
                return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes)
    {
        int i;
        vector<int> colors(n, -1);
        unordered_map<int, vector<int>> adjList;

        for (auto d : dislikes) {
            adjList[d[0]].push_back(d[1]);
            adjList[d[1]].push_back(d[0]);
        }

        for (auto i = 0; i < n; ++i) {
            if (adjList.find(i + 1) != adjList.end() && colors[i] == -1) {
                colors[i] = 0;
                if (!dfs(adjList, colors, i + 1)) {
                    return false;
                }
            }
        }

        return true;
    }
};

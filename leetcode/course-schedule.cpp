#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool hasCycle(unordered_map<int, vector<int>>& adjList, vector<int>& colors, int i)
    {
        // 0 - White, 1 - Gray, 2 - Black
        colors[i] = 1;
        for (auto j : adjList[i]) {
            if ((colors[j] == 0 && hasCycle(adjList, colors, j)) || colors[j] == 1)
                return true;
        }
        colors[i] = 2;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        unordered_map<int, vector<int>> adjList;
        vector<int> colors(numCourses);

        for (auto p : prerequisites) {
            adjList[p[0]].push_back(p[1]);
        }

        for (auto i = 0; i < numCourses; ++i) {
            if (adjList.find(i) != adjList.end() && colors[i] == 0 &&
                hasCycle(adjList, colors, i)) {
                return false;
            }
        }

        return true;
    }
};

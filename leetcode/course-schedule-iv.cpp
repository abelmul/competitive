#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries)
    {
        vector<vector<int>> adjList(numCourses);
        vector<vector<long long>> dist(numCourses, vector<long long>(numCourses, INT_MAX));

        vector<bool> res;

        for (auto p : prerequisites) {
            adjList[p[0]].push_back(p[1]);
            dist[p[0]][p[1]] = 1;
        }

        for (auto i = 0; i < numCourses; ++i) {
            dist[i][i] = 0;
        }

        for (auto k = 0; k < numCourses; ++k) {
            for (auto i = 0; i < numCourses; ++i) {
                for (auto j = 0; j < numCourses; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        for (auto q : queries) {
            res.push_back(dist[q[0]][q[1]] != INT_MAX);
        }

        return res;
    }
};

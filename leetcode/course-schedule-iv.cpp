#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries)
    {
        vector<bool> res;

        vector<int> indegree(numCourses);
        unordered_map<int, set<int>> prereqs;
        unordered_map<int, vector<int>> adjList;
        deque<int> queue;

        res.reserve(queries.size());

        for (auto p : prerequisites) {
            adjList[p[0]].push_back(p[1]);
            ++indegree[p[1]];
        }

        // topological sort
        for (auto i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                queue.emplace_back(i);
                prereqs[i] = {};
            }
        }

        while (!queue.empty()) {
            auto t = queue.front();
            queue.pop_front();

            for (auto i : adjList[t]) {
                --indegree[i];
                prereqs[i].insert(t);
                prereqs[i].insert(prereqs[t].begin(), prereqs[t].end());

                if (indegree[i] == 0) {
                    queue.emplace_back(i);
                }
            }
        }

        // result
        for (auto q : queries) {
            res.push_back(prereqs[q[1]].find(q[0]) != prereqs[q[1]].end());
        }

        return res;
    }
};

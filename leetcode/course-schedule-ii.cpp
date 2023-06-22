#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(numCourses);
        deque<int> queue;

        vector<int> res;

        for (auto pre : prerequisites) {
            adjList[pre[1]].push_back(pre[0]);
            ++indegree[pre[0]];
        }

        for (auto i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0)
                queue.push_back(i);
        }

        while (!queue.empty()) {
            auto i = queue.front();
            queue.pop_front();

            res.push_back(i);

            for (auto j : adjList[i]) {
                --indegree[j];
                if (indegree[j] == 0) {
                    queue.push_back(j);
                }
            }
        }

        if (res.size() != numCourses)
            return {};

        return res;
    }
};

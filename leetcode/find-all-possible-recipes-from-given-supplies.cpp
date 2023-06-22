#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients,
                                  vector<string>& supplies)
    {
        auto size = recipes.size();

        vector<string> res;

        unordered_map<string, vector<int>> adjList;
        deque<string> queue;
        vector<int> indegree(size);
        string cur;

        for (auto i = 0; i < size; ++i) {
            indegree[i] += ingredients[i].size();
            for (auto ing : ingredients[i]) {
                adjList[ing].push_back(i);
            }
        }

        for (auto s : supplies) {
            queue.push_back(s);
        }

        while (!queue.empty()) {
            cur = queue.front();
            queue.pop_front();

            for (auto i : adjList[cur]) {
                --indegree[i];
                if (indegree[i] == 0) {
                    res.push_back(recipes[i]);
                    queue.push_back(recipes[i]);
                }
            }
        }

        return res;
    }
};

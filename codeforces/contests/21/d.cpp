#include <bits/stdc++.h>

using namespace std;

/**
 * Cyclic Components
 * https://codeforces.com/gym/444629/problem/D
 *
 * Time - O(V+E)
 * Space - O(n)
 */

bool isCyclic(map<int, int>& indegree)
{
    for (auto& [k, v] : indegree) {
        if (v != 2) {
            return false;
        }
    }

    return true;
}

void dfs(unordered_map<int, vector<int>>& adjList, int i, vector<bool>& visited,
         map<int, int>& indegree)
{
    ++indegree[i - 1];
    if (visited[i - 1] == false) {
        visited[i - 1] = true;

        for (auto u : adjList[i]) {
            dfs(adjList, u, visited, indegree);
        }
    }
}

int main()
{
    int n, m;
    int v, u;

    unordered_map<int, vector<int>> adjList;
    vector<bool> visited;
    map<int, int> indegree;

    int res = 0;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    visited.resize(n);

    for (auto i = 0; i < m; ++i) {
        cin >> v >> u;

        adjList[v].push_back(u);
        adjList[u].push_back(v);
    }

    for (auto i = 0; i < n; ++i) {
        if (visited[i] == false) {
            indegree[i] = -1;

            dfs(adjList, i + 1, visited, indegree);
            res += isCyclic(indegree);

            indegree.clear();
        }
    }

    cout << res << "\n";

    return 0;
}

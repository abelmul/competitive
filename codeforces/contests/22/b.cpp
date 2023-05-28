#include <bits/stdc++.h>

using namespace std;

/**
 * Brain Network (easy)
 * https://codeforces.com/gym/445680/B
 *
 * Time - O(n + m)
 * Space - O(n)
 */

bool isCyclic(unordered_map<int, vector<int>> adjList, vector<bool>& visited, int i, int parent)
{
    visited[i - 1] = true;

    for (auto j : adjList[i]) {
        if (!visited[j - 1]) {
            if (isCyclic(adjList, visited, j, i)) {
                return true;
            }
        } else if (j != parent) {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    int a, b;
    unordered_map<int, vector<int>> adjList;

    vector<bool> visited;

    string res = "yes";

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    visited.resize(n);

    for (auto i = 0; i < m; ++i) {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    if (!isCyclic(adjList, visited, 1, -1)) {
        for (auto i = 0; i < n; ++i) {
            if (!visited[i])
                res = "no";
        }
    } else {
        res = "no";
    }

    cout << res << "\n";

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

/**
 * Graph Without Long Directed Paths
 * https://codeforces.com/gym/444629/problem/E
 *
 * Time - O(n+m)
 * Space - O(n)
 */

bool isBipartite(unordered_map<int, vector<int>>& adjList, vector<int>& visited, vector<int>& color,
                 int i)
{
    if (visited[i - 1])
        return true;

    for (auto j : adjList[i]) {
        if (color[j - 1] == -1) {
            color[j - 1] = !color[i - 1];
            if (!isBipartite(adjList, visited, color, j)) {
                return false;
            }
        } else if (color[j - 1] != !color[i - 1]) {
            return false;
        }
    }

    return true;
}

int main()
{
    int n, m;
    int u, v;

    vector<pair<int, int>> edgeList;
    unordered_map<int, vector<int>> adjList;
    vector<int> colors, visited;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    colors.resize(n);
    visited.resize(n);
    edgeList.resize(m);

    fill(colors.begin(), colors.end(), -1);

    for (auto i = 0; i < m; ++i) {
        cin >> u >> v;

        edgeList[i].first = u;
        edgeList[i].second = v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    colors[0] = 0;
    if (isBipartite(adjList, visited, colors, 1)) {
        cout << "YES\n";
        for (auto i = 0; i < m; ++i) {
            char print = colors[edgeList[i].first - 1] == 1 ? '0' : '1';
            cout << print;
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

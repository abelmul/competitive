#include <bits/stdc++.h>

using namespace std;

/**
 * The Lakes
 * https://codeforces.com/gym/445680/problem/C
 *
 * Time - O(n + m)
 * Space - O(n + m)
 */

const pair<int, int> dirs[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int dfs(const vector<vector<int>>& adjMatrix, set<pair<int, int>>& visited, int i, int j)
{
    if (visited.find({i, j}) != visited.end())
        return 0;

    int res = adjMatrix[i][j];

    int r, c;

    visited.insert({i, j});

    for (auto d : dirs) {
        r = i + d.first;
        c = j + d.second;

        if (r >= 0 && c >= 0 && r < adjMatrix.size() && c < adjMatrix[0].size() &&
            adjMatrix[r][c] > 0) {
            res += dfs(adjMatrix, visited, r, c);
        }
    }

    return res;
}

int main()
{
    int t, n, m;

    vector<vector<int>> adjMatrix;
    set<pair<int, int>> visited;

    int res = 0;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> m;

        adjMatrix.resize(n);

        for (auto i = 0; i < n; ++i) {
            adjMatrix[i].resize(m);
            for (auto j = 0; j < m; ++j) {
                cin >> adjMatrix[i][j];
            }
        }

        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (adjMatrix[i][j] > 0 && visited.find({i, j}) == visited.end()) {
                    res = max(res, dfs(adjMatrix, visited, i, j));
                }
            }
        }

        cout << res << "\n";

        visited.clear();
        res = 0;
    }

    return 0;
}

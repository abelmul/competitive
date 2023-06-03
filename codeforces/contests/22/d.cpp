#include <bits/stdc++.h>

using namespace std;

/**
 * Maze
 * https://codeforces.com/gym/445680/problem/D
 *
 * Time - O(n)
 * Space - O(n)
 */

int main()
{
    int n, m, k;

    vector<vector<char>> grid;

    const pair<int, int> dirs[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    deque<pair<int, int>> queue;
    set<pair<int, int>> visited;

    int x = 0;
    int ci, cj;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    grid.resize(n);

    for (auto i = 0; i < n; ++i) {
        grid[i].resize(m);
        for (auto j = 0; j < m; ++j) {
            cin >> grid[i][j];

            x += (grid[i][j] == '.');
        }
    }

    // we need x - k empty cells
    x -= k;

    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < m; ++j) {
            if (grid[i][j] == '.') {
                // bfs until we fullfil x
                queue.push_back({i, j});

                while (!queue.empty() && visited.size() < x) {
                    tie(ci, cj) = queue.front();
                    queue.pop_front();

                    if (visited.find({ci, cj}) != visited.end())
                        continue;
                    visited.insert({ci, cj});

                    for (auto d : dirs) {
                        int r = ci + d.first, c = cj + d.second;

                        if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == '.') {
                            queue.push_back({r, c});
                        }
                    }
                }
                break;
            }
        }
        if (visited.size() >= x)
            break;
    }

    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < m; ++j) {
            if (grid[i][j] == '.' && visited.find({i, j}) == visited.end())
                grid[i][j] = 'X';
        }
    }

    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < m; ++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }

    return 0;
}

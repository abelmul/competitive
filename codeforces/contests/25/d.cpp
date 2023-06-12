#include <bits/stdc++.h>

using namespace std;

/**
 * Fox And Two Dots
 * https://codeforces.com/gym/447850/problem/D
 *
 * Time - O(n)
 * Space - O(n)
 */

const pair<int, int> dirs[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool has_cycle(const vector<string>& grid, set<pair<int, int>>& visited, pair<int, int> pos,
               pair<int, int> parent)
{
    bool found_cycle = false;

    visited.insert(pos);

    int r, c;

    for (auto d : dirs) {
        r = pos.first + d.first;
        c = pos.second + d.second;
        if (r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() &&
            grid[r][c] == grid[pos.first][pos.second]) {
            if (visited.find({r, c}) == visited.end()) {
                if (has_cycle(grid, visited, {r, c}, pos)) {
                    found_cycle = true;
                }
            } else if (make_pair(r, c) != parent) {
                found_cycle = true;
            }
        }
    }

    return found_cycle;
}

int main()
{
    int n, m;
    bool found_cycle = false;

    vector<string> grid;
    set<pair<int, int>> visited, cycle_visited;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    grid.resize(n);
    for (auto i = 0; i < n; ++i) cin >> grid[i];

    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < m; ++j) {
            if (visited.find({i, j}) == visited.end()) {
                cycle_visited.clear();

                if (has_cycle(grid, cycle_visited, {i, j}, {-1, -1}) && cycle_visited.size() >= 4) {
                    found_cycle = true;
                    break;
                }

                for (auto p : cycle_visited) {
                    visited.insert(p);
                }
            }
        }
    }

    if (found_cycle) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}

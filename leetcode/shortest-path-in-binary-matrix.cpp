#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        auto n = grid.size(), m = grid[0].size();
        const pair<int, int> dirs[] = {
            {-1, 1}, {0, 1}, {1, 1}, {-1, 0}, {1, 0}, {-1, -1}, {0, -1}, {1, -1},
        };

        int row, col, r, c;
        int res = -1;

        if (grid[0][0] == 0 && grid[n - 1][m - 1] == 0) {
            deque<pair<int, int>> queue;
            vector<vector<int>> prev(n, vector<int>(m, -1));

            queue.push_back({0, 0});
            prev[0][0] = 1;

            while (!queue.empty()) {
                tie(row, col) = queue.front();
                queue.pop_front();

                if (row == n - 1 && col == m - 1)
                    break;

                for (auto d : dirs) {
                    r = row + d.first;
                    c = col + d.second;

                    if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 0 && prev[r][c] == -1) {
                        prev[r][c] = prev[row][col] + 1;
                        queue.push_back({r, c});
                    }
                }
            }

            if (prev[n - 1][m - 1] != -1) {
                res = prev[n - 1][m - 1];
            }
        }

        return res;
    }
};

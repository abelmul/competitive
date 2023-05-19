#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        auto n = grid.size(), m = grid[0].size();

        vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        int row, col;

        if (grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;
        int res = 1;

        for (auto d : dirs) {
            row = i + d.first;
            col = j + d.second;

            if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 1) {
                res += dfs(grid, row, col);
            }
        }

        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        auto n = grid.size(), m = grid[0].size();

        int res = 0;

        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    // dfs
                    res = max(res, dfs(grid, i, j));
                }
            }
        }

        return res;
    }
};

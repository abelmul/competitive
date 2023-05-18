#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        auto n = grid.size(), m = grid[0].size();

        vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        int row, col;

        if (grid[i][j] == '0')
            return;

        grid[i][j] = '0';

        for (auto d : dirs) {
            row = i + d.first;
            col = j + d.second;

            if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == '1') {
                dfs(grid, row, col);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        auto n = grid.size(), m = grid[0].size();

        int res = 0;

        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    // dfs
                    dfs(grid, i, j);

                    ++res;
                }
            }
        }

        return res;
    }
};

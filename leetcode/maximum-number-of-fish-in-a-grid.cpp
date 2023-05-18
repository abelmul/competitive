#include <bits/stdc++.h>

using namespace std;

class Solution
{
 private:
    const int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

 public:
    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        auto n = grid.size(), m = grid[0].size();
        int row, col;
        int res = 0;

        if (grid[i][j] != 0) {
            res += grid[i][j];
            grid[i][j] = 0;

            for (auto d : dirs) {
                row = i + d[0];
                col = j + d[1];

                if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] > 0) {
                    res += dfs(grid, row, col);
                }
            }
        }

        return res;
    }

    int findMaxFish(vector<vector<int>>& grid)
    {
        auto n = grid.size(), m = grid[0].size();

        int res = 0;

        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (grid[i][j] > 0) {
                    // dfs
                    res = max(res, dfs(grid, i, j));
                }
            }
        }

        return res;
    }
};

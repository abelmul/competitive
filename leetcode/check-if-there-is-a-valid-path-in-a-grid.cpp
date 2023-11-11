#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool hasValidPath(vector<vector<int>>& grid)
    {
        auto m = grid.size();
        auto n = grid[0].size();

        vector<vector<pair<int, int>>> root(m, vector<pair<int, int>>(n, {0, 0}));
        vector<vector<int>> rank(m, vector<int>(n, 1));

        function<pair<int, int>(pair<int, int>)> find = [&](pair<int, int> pos) {
            if (pos != root[pos.first][pos.second]) {
                root[pos.first][pos.second] = find(root[pos.first][pos.second]);
            }

            return root[pos.first][pos.second];
        };

        auto join = [&](pair<int, int> x, pair<int, int> y) {
            auto rootX = find(x);
            auto rootY = find(y);

            if (rootX != rootY) {
                if (rank[rootY.first][rootY.second] > rank[rootX.first][rootX.second]) {
                    swap(rootY, rootX);
                }

                root[rootY.first][rootY.second] = rootX;
                rank[rootX.first][rootX.second] += rank[rootY.first][rootY.second];
            }
        };

        // init root
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                root[i][j] = {i, j};
            }
        }

        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                switch (grid[i][j]) {
                    case 1:
                        // cell to the right must be 1, 3 or 5 to be joined
                        if (j + 1 < n &&
                            (grid[i][j + 1] == 1 or grid[i][j + 1] == 3 or grid[i][j + 1] == 5)) {
                            join({i, j}, {i, j + 1});
                        }
                        break;
                    case 2:
                        // cell below must be 2, 5 or 6  to be joined
                        if (i + 1 < m &&
                            (grid[i + 1][j] == 2 or grid[i + 1][j] == 5 or grid[i + 1][j] == 6)) {
                            join({i, j}, {i + 1, j});
                        }
                        break;
                    case 3:
                        // cell below must be 2, 5 or 6 to be joined
                        if (i + 1 < m &&
                            (grid[i + 1][j] == 2 or grid[i + 1][j] == 5 or grid[i + 1][j] == 6)) {
                            join({i, j}, {i + 1, j});
                        }
                        break;
                    case 4:
                        // cell below must be 2, 5 or 6 to be joined
                        if (i + 1 < m &&
                            (grid[i + 1][j] == 2 or grid[i + 1][j] == 5 or grid[i + 1][j] == 6)) {
                            join({i, j}, {i + 1, j});
                        }
                        // cell to the right must be 1, 3 or 5 to be joined
                        if (j + 1 < n &&
                            (grid[i][j + 1] == 1 or grid[i][j + 1] == 3 or grid[i][j + 1] == 5)) {
                            join({i, j}, {i, j + 1});
                        }
                        break;
                    case 5:
                        break;
                    case 6:
                        // cell to the right must be 1, 3 or 5 to be joined
                        if (j + 1 < n &&
                            (grid[i][j + 1] == 1 or grid[i][j + 1] == 3 or grid[i][j + 1] == 5)) {
                            join({i, j}, {i, j + 1});
                        }
                        break;
                }
            }
        }

        return find({0, 0}) == find({m - 1, n - 1});
    }
};

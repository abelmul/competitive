#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    void solve(vector<vector<char>>& board)
    {
        const pair<int, int> dirs[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        auto m = board.size(), n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> coordinates;

        bool isSurrounded;

        function<bool(int, int, vector<pair<int, int>>&)> dfs =
            [&](int row, int col, vector<pair<int, int>>& coordinates) {
                bool res = true;

                if (visited[row][col] == false) {
                    visited[row][col] = true;

                    coordinates.push_back({row, col});

                    for (auto d : dirs) {
                        auto r = row + d.first, c = col + d.second;

                        if (r >= 0 && r < m && c >= 0 && c < n) {
                            if (board[r][c] == 'O') {
                                res &= dfs(r, c, coordinates);
                            }
                        } else {
                            res = false;
                        }
                    }
                }

                return res;
            };

        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    coordinates.clear();
                    isSurrounded = dfs(i, j, coordinates);

                    if (isSurrounded) {
                        for (auto c : coordinates) {
                            board[c.first][c.second] = 'X';
                        }
                    }
                }
            }
        }
    }
};

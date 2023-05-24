#include <bits/stdc++.h>

using namespace std;

class Solution
{
 private:
    array<array<int, 9>, 9> rows, cols, boxes;

 public:
    bool isValid(int row, int col, char value)
    {
        int k = (row / 3) * 3 + (col / 3);
        int b = value - '1';

        if (rows[row][b] || cols[col][b] || boxes[k][b])
            return false;

        ++rows[row][b];
        ++cols[col][b];
        ++boxes[k][b];

        return true;
    }

    void unset(int row, int col, char value)
    {
        int k = (row / 3) * 3 + (col / 3);
        int b = value - '1';

        --rows[row][b];
        --cols[col][b];
        --boxes[k][b];
    }

    bool backtrack(vector<vector<char>>& board)
    {
        for (auto i = 0; i < 9; ++i) {
            for (auto j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (auto k = 0; k < 9; ++k) {
                        if (isValid(i, j, '1' + k)) {
                            board[i][j] = '1' + k;
                            if (backtrack(board)) {
                                return true;
                            }
                            unset(i, j, '1' + k);
                        }
                        board[i][j] = '.';
                    }

                    if (board[i][j] == '.')
                        return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        int unfilled = 0;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int k = (i / 3) * 3 + (j / 3);
                    auto b = board[i][j] - '1';

                    ++rows[i][b];
                    ++cols[j][b];
                    ++boxes[k][b];
                } else {
                    ++unfilled;
                }
            }
        }
        backtrack(board);
    }
};

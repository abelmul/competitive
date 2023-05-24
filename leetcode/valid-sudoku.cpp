#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int rows[9][9] = {0}, cols[9][9] = {0}, boxes[9][9] = {};
        int b, k;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] != '.') {
                    k = (i / 3) * 3 + (j / 3);
                    b = board[j][i] - '1';

                    if (rows[i][b] || cols[j][b] || boxes[k][b])
                        return false;

                    ++rows[i][b];
                    ++cols[j][b];
                    ++boxes[k][b];
                }
            }
        }

        return true;
    }
};

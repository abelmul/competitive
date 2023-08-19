#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        int row = mat.size(), col = mat[0].size();

        function<int(int, int)> get = [&](int r, int c) {
            if (r >= 0 && r < row && c >= 0 && c < col) {
                return mat[r][c];
            }
            return 1000000000;  // see constraints
        };

        // top -> down
        // left -> right
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (mat[i][j]) {
                    mat[i][j] = 1 + min(get(i - 1, j), get(i, j - 1));
                }
            }
        }

        // down -> top
        // right -> left
        for (int i = row - 1; i >= 0; --i) {
            for (int j = col - 1; j >= 0; --j) {
                if (mat[i][j]) {
                    mat[i][j] = min(mat[i][j], 1 + min(get(i + 1, j), get(i, j + 1)));
                }
            }
        }

        return mat;
    }
};

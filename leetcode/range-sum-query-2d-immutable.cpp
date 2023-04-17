#include <bits/stdc++.h>
using namespace std;
class NumMatrix
{
 private:
    vector<vector<int>> data;

 public:
    NumMatrix(vector<vector<int>>& matrix) : data(matrix)
    {
        auto data_column_size = data.size();
        auto data_row_size = data[0].size();

        for (int i = 0; i < data_column_size; ++i) {
            for (int j = 0; j < data_row_size; ++j) {
                if (i == 0 && j == 0)
                    continue;

                data[i][j] += get_at(i - 1, j) + get_at(i, j - 1) - get_at(i - 1, j - 1);
            }
        }
    }

    int get_at(int row, int column) { return (row < 0 || column < 0) ? 0 : data[row][column]; }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return data[row2][col2] + get_at(row1 - 1, col1 - 1) - get_at(row2, col1 - 1) -
               get_at(row1 - 1, col2);
    }
};

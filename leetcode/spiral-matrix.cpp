#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> res;

        int n = matrix.size(), m = matrix[0].size();
        int r = 0, c = 0;

        bool reverse = false;
        res.reserve(n * m);

        while (r < n && c < m) {
            if (reverse) {
                for (auto i = m - 1; i >= c; --i) res.push_back(matrix[n - 1][i]);
                --n;

                for (auto i = n - 1; i >= r; --i) res.push_back(matrix[i][c]);
                ++c;
            } else {
                for (auto i = c; i < m; ++i) res.push_back(matrix[r][i]);
                ++r;

                for (auto i = r; i < n; ++i) res.push_back(matrix[i][m - 1]);
                --m;
            }
            reverse = !reverse;
        }

        return res;
    }
};

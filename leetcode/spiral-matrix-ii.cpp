class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));

        int r = 0, c = 0, m = n;

        int counter = 1;

        while(r < n && c < m) {
           // left -> right
           for(auto i = c; i < m; ++i) {
               matrix[r][i] = counter++;
           }
           ++r;

           // up -> down
           for(auto i = r; i < n; ++i) {
               matrix[i][m - 1] = counter++;
           }
           --m;

           // right -> left
           for(auto i = m - 1; i >= c; --i) {
               matrix[n - 1][i] = counter++;
           }
           --n;

           // down -> up
           for(auto i = n - 1; i >= r; --i) {
               matrix[i][c] = counter++;
           }
           ++c;
        }

        return matrix;
    }
};
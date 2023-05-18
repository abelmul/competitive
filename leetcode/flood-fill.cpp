#include <bits/stdc++.h>

using namespace std;

class Solution
{
 private:
    const int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

 public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        auto n = image.size(), m = image[0].size();
        int st_color = image[sr][sc];

        int row, col;
        stack<pair<int, int>> st;
        set<pair<int, int>> visited;

        st.push({sr, sc});

        while (!st.empty()) {
            tie(sr, sc) = st.top();
            st.pop();

            if (visited.find({sr, sc}) != visited.end())
                continue;

            image[sr][sc] = color;
            visited.insert({sr, sc});

            for (auto d : dirs) {
                row = sr + d[0];
                col = sc + d[1];

                if (row >= 0 && row < n && col >= 0 && col < m && image[row][col] == st_color) {
                    st.push({row, col});
                }
            }
        }

        return image;
    }
};

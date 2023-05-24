#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        auto n = grid.size(), m = grid[0].size();

        const pair<int, int> dirs[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        deque<tuple<int, int, int>> queue;
        set<pair<int, int>> visited;

        int fresh = 0, res = 0;

        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    queue.push_back({i, j, 1});
                } else if (grid[i][j] == 1) {
                    ++fresh;
                }
            }
        }

        while (!queue.empty()) {
            auto pos = queue.front();
            queue.pop_front();

            if (visited.find({get<0>(pos), get<1>(pos)}) != visited.end())
                continue;

            visited.insert({get<0>(pos), get<1>(pos)});

            int row, col;
            for (auto d : dirs) {
                row = get<0>(pos) + d.first;
                col = get<1>(pos) + d.second;
                if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 1) {
                    res = get<2>(pos);
                    grid[row][col] = 2;
                    queue.push_back({row, col, get<2>(pos) + 1});
                    --fresh;
                }
            }
        }

        return fresh == 0 ? res : -1;
    }
};

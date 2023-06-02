#include <bits/stdc++.h>

using namespace std;

class Solution
{
 private:
    const pair<int, int> dirs[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

 public:
    void dfs(const vector<vector<int>>& grid, deque<pair<int, int>>& queue,
             map<pair<int, int>, int>& prev, int i, int j)
    {
        if (prev.find({i, j}) != prev.end())
            return;

        int r, c;

        prev[{i, j}] = 0;
        queue.push_back({i, j});

        for (auto d : dirs) {
            r = i + d.first;
            c = j + d.second;

            if (r >= 0 && c >= 0 && r < grid.size() && c < grid.size() && grid[r][c] == 1) {
                dfs(grid, queue, prev, r, c);
            }
        }
    }

    void getFirstIsland(const vector<vector<int>>& grid, deque<pair<int, int>>& queue,
                        map<pair<int, int>, int>& prev)
    {
        auto n = grid.size();

        // dfs to get the first connected component(island)
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, queue, prev, i, j);
                    return;
                }
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid)
    {
        auto n = grid.size();
        int res = INT_MAX;

        deque<pair<int, int>> queue;
        pair<int, int> pos;
        map<pair<int, int>, int> prev;

        int r, c;

        getFirstIsland(grid, queue, prev);

        while (!queue.empty()) {
            pos = queue.front();
            queue.pop_front();

            for (auto d : dirs) {
                r = pos.first + d.first;
                c = pos.second + d.second;
                if (r >= 0 && c >= 0 && r < n && c < n && prev.find({r, c}) == prev.end()) {
                    if (prev[pos] > 0 && grid[r][c] == 1) {
                        // second island found
                        res = min(res, prev[pos]);
                        continue;
                    }
                    prev[{r, c}] = prev[pos] + (grid[r][c] == 0);
                    queue.push_back({r, c});
                }
            }
        }

        return res;
    }
};

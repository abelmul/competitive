#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    inline bool isExit(const vector<int>& entrance, const int n, const int m, int r, int c)
    {
        return (r != entrance[0] || c != entrance[1]) &&
               (r == 0 || c == 0 || r == n - 1 || c == m - 1);
    }

    int nearestExit(vector<vector<char>>& maze, vector<int> entrance)
    {
        auto n = maze.size(), m = maze[0].size();

        const pair<int, int> dirs[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        pair<int, int> current;
        deque<pair<int, int>> queue;
        map<pair<int, int>, int> prev;

        int r, c;
        int res = INT_MAX;

        queue.push_back({entrance[0], entrance[1]});
        prev[{entrance[0], entrance[1]}] = 0;

        while (!queue.empty()) {
            current = queue.front();
            queue.pop_front();

            if (isExit(entrance, n, m, current.first, current.second)) {
                res = prev[current];
                break;
            }

            for (auto d : dirs) {
                r = current.first + d.first;
                c = current.second + d.second;

                if (r >= 0 && r < n && c >= 0 && c < m && maze[r][c] != '+' &&
                    prev.find({r, c}) == prev.end()) {
                    queue.push_back({r, c});
                    prev[{r, c}] = prev[current] + 1;
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};

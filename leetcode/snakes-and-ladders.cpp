#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    pair<int, int> getRowAndCol(int num, int n)
    {
        if (((num - 1) / n) % 2 == 0)
            return {n - (num / n + (num % n != 0)), (num - 1) % n};

        return {n - (num / n + (num % n != 0)), n - 1 - (num - 1) % n};
    }

    int snakesAndLadders(vector<vector<int>>& board)
    {
        int n = board.size();
        int res = INT_MAX;

        int num, j;
        pair<int, int> pos;
        deque<int> queue;
        unordered_map<int, int> prev;

        queue.push_back(1);
        prev[1] = 0;

        while (!queue.empty()) {
            num = queue.front();
            queue.pop_front();

            for (auto i = num + 1; i <= min(num + 6, n * n); ++i) {
                if (i == n * n) {
                    res = min(res, prev[num] + 1);
                    continue;
                }

                pos = getRowAndCol(i, n);
                j = board[pos.first][pos.second];

                if (j != -1) {
                    if (j == n * n) {
                        res = min(res, prev[num] + 1);
                        continue;
                    }

                    if (prev.find(j) == prev.end()) {
                        prev[j] = prev[num] + 1;
                        queue.push_back(j);
                    }
                    continue;
                }

                if (prev.find(i) == prev.end()) {
                    queue.push_back(i);
                    prev[i] = prev[num] + 1;
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};

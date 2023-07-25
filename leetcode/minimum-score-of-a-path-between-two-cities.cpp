#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int minScore(int n, vector<vector<int>>& roads)
    {
        int res = INT_MAX;

        // union-find ds
        vector<int> root(n + 1), rank(n + 1, 1);

        iota(root.begin(), root.end(), 0);

        function<int(int)> find = [&](int x) {
            if (x != root[x]) {
                root[x] = find(root[x]);
            }

            return root[x];
        };

        auto join = [&](int x, int y) {
            auto rootX = find(x), rootY = find(y);

            if (rootX != rootY) {
                if (rank[rootY] > rank[rootX]) {
                    swap(rootX, rootY);
                }

                root[rootY] = rootX;
                rank[rootX] += rank[rootY];
            }
        };

        for (auto r : roads) {
            join(r[0], r[1]);
        }

        for (auto r : roads) {
            if (find(r[0]) == find(1)) {
                res = min(res, r[2]);
            }
        }

        return res;
    }
};

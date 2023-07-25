#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        auto n = points.size();
        vector<tuple<int, pair<int, int>, pair<int, int>>> edgeList;

        int res = 0;
        map<pair<int, int>, pair<int, int>> root;
        map<pair<int, int>, int> rank;

        function<pair<int, int>(pair<int, int>)> find = [&](pair<int, int> pos) {
            if (pos != root[pos]) {
                root[pos] = find(root[pos]);
            }

            return root[pos];
        };

        auto join = [&](pair<int, int> x, pair<int, int> y) {
            auto rootX = find(x);
            auto rootY = find(y);

            if (rootX != rootY) {
                if (rank[rootY] > rank[rootX]) {
                    swap(rootY, rootX);
                }

                root[rootY] = rootX;
                rank[rootX] += rank[rootY];
                return true;
            }

            return false;
        };

        edgeList.reserve(n * n);
        for (auto i = 0; i < n; ++i) {
            for (auto j = i + 1; j < n; ++j) {
                edgeList.push_back(
                    {abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]),
                     {points[i][0], points[i][1]},
                     {points[j][0], points[j][1]}});
            }
        }

        sort(edgeList.begin(), edgeList.end());

        for (auto e : edgeList) {
            root.try_emplace(get<1>(e), get<1>(e));
            root.try_emplace(get<2>(e), get<2>(e));
            rank.try_emplace(get<1>(e), 1);
            rank.try_emplace(get<2>(e), 1);

            if (join(get<1>(e), get<2>(e))) {
                res += get<0>(e);
            }
        }

        return res;
    }
};

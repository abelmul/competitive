#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int removeStones(vector<vector<int>>& stones)
    {
        int res = 0;

        // union find ds
        // 0 - ROW
        // 1 - COL
        map<pair<int, int>, pair<int, int>> root;
        map<pair<int, int>, int> rank;

        set<pair<int, int>> unions;

        function<pair<int, int>(pair<int, int>)> find = [&](pair<int, int> pos) {
            if (pos != root[pos]) {
                root[pos] = find(root[pos]);
            }
            return root[pos];
        };

        auto join = [&](pair<int, int> x, pair<int, int> y) {
            auto rootX = find(x), rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootY] > rank[rootX]) {
                    swap(rootX, rootY);
                }

                root[rootY] = rootX;
                rank[rootX] += rank[rootY];
            }
        };

        for (auto s : stones) {
            root.try_emplace({0, s[0]}, 0, s[0]);
            root.try_emplace({1, s[1]}, 1, s[1]);
            rank.try_emplace({0, s[0]}, 1);
            rank.try_emplace({1, s[1]}, 1);

            join({0, s[0]}, {1, s[1]});
        }

        for (auto s : stones) {
            unions.insert(find({0, s[0]}));
        }

        return stones.size() - unions.size();
    }
};

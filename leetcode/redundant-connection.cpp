#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    void join(vector<int>& root, vector<int>& rank, int x, int y)
    {
        auto rootX = find(root, x);
        auto rootY = find(root, y);

        if (rootX != rootY) {
            if (rank[rootY] > rank[rootX]) {
                swap(rootY, rootX);
            }

            root[rootY] = rootX;
            rank[rootX] = rank[rootY];
        }
    }

    int find(vector<int>& root, int x)
    {
        if (x != root[x]) {
            root[x] = find(root, root[x]);
        }

        return root[x];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        auto n = edges.size();

        vector<int> root(n + 1), rank(n + 1, 1);

        iota(root.begin(), root.end(), 0);

        for (auto e : edges) {
            if (find(root, e[0]) == find(root, e[1])) {
                return e;
            }
            join(root, rank, e[0], e[1]);
        }

        return edges.back();
    }
};

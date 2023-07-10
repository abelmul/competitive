#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    void join(vector<int>& root, vector<int>& rank, int i, int j)
    {
        auto rootI = find(root, i);
        auto rootJ = find(root, j);

        if (rootI != rootJ) {
            if (rank[rootI] > rank[rootJ]) {
                root[rootJ] = root[rootI];
                rank[rootI] += rank[rootJ];
            } else {
                root[rootI] = root[rootJ];
                rank[rootJ] += rank[rootI];
            }
        }
    }

    int find(vector<int>& root, int i)
    {
        if (i != root[i]) {
            root[i] = find(root, root[i]);
        }

        return root[i];
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        vector<int> root(n), rank(n, 1);

        iota(root.begin(), root.end(), 0);

        for (auto e : edges) {
            join(root, rank, e[0], e[1]);
        }

        return find(root, source) == find(root, destination);
    }
};

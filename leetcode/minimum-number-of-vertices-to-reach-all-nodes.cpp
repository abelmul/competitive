#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges)
    {
        vector<int> incoming(n);
        vector<int> res;

        for (auto e : edges) {
            ++incoming[e[1]];
        }

        for (auto i = 0; i < n; ++i) {
            if (incoming[i] == 0)
                res.emplace_back(i);
        }

        return res;
    }
};

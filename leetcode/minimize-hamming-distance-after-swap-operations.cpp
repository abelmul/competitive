#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int find(vector<int>& root, int i)
    {
        if (root[i] != i) {
            root[i] = find(root, root[i]);
        }
        return root[i];
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps)
    {
        int res = 0;

        auto n = source.size();
        vector<int> root(n), rank(n, 1);

        vector<unordered_multiset<int>> available_swaps(n);

        iota(root.begin(), root.end(), 0);

        for (auto a : allowedSwaps) {
            auto i = find(root, a[0]);
            auto j = find(root, a[1]);

            if (i != j) {
                if (rank[j] > rank[i]) {
                    swap(i, j);
                }

                root[j] = i;
                rank[i] += rank[j];
            }
        }

        for (auto i = 0; i < n; ++i) {
            if (source[i] != target[i]) {
                available_swaps[find(root, i)].insert(source[i]);
            }
        }

        for (auto i = 0; i < n; ++i) {
            if (source[i] != target[i]) {
                auto j = find(root, i);
                if (available_swaps[j].find(target[i]) != available_swaps[j].end()) {
                    available_swaps[j].erase(available_swaps[j].find(target[i]));
                } else {
                    ++res;
                }
            }
        }

        return res;
    }
};

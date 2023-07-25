#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
    {
        auto n = s.size();
        vector<int> root(n), rank(n, 1);
        string res;
        unordered_map<int, priority_queue<char, vector<char>, greater<char>>> unions;

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

        for (auto p : pairs) {
            join(p[0], p[1]);
        }

        for (auto i = 0; i < n; ++i) {
            unions[find(i)].push(s[i]);
        }

        res.reserve(n);

        for (auto i = 0; i < n; ++i) {
            res.push_back(unions[find(i)].top());
            unions[find(i)].pop();
        }

        return res;
    }
};

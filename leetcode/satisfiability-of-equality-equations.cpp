#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool equationsPossible(vector<string>& equations)
    {
        unordered_map<char, char> root;
        unordered_map<char, int> rank;

        function<char(char)> find = [&](char c) {
            if (root.find(c) != root.end()) {
                if (c != root[c]) {
                    root[c] = find(root[c]);
                }
            } else {
                root[c] = c;
                rank[c] = 1;
            }
            return root[c];
        };

        auto join = [&](char x, char y) {
            auto rootX = find(x);
            auto rootY = find(y);

            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    swap(rootX, rootY);
                }

                root[rootY] = rootX;
                rank[rootX] += rank[rootY];
            }
        };

        for (auto e : equations) {
            if (e[1] == '=') {
                join(e[0], e[3]);
            }
        }

        for (auto e : equations) {
            if (e[1] == '!' && find(e[0]) == find(e[3])) {
                return false;
            }
        }
        return true;
    }
};

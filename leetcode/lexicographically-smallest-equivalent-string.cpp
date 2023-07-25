#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        auto n = s1.size();

        char root[26];

        string res;

        // init
        res.reserve(baseStr.size());
        iota(begin(root), end(root), 'a');

        function<char(char)> find = [&](char x) {
            if (x != root[x - 'a']) {
                root[x - 'a'] = find(root[x - 'a']);
            }

            return root[x - 'a'];
        };
        auto join = [&](char x, char y) {
            auto rootX = find(x);
            auto rootY = find(y);

            if (rootX != rootY) {
                if (rootX > rootY) {
                    swap(rootX, rootY);
                }

                root[rootY - 'a'] = rootX;
            }
        };

        for (auto i = 0; i < n; ++i) {
            join(s1[i], s2[i]);
        }

        for (auto c : baseStr) {
            res.push_back(find(c));
        }

        return res;
    }
};

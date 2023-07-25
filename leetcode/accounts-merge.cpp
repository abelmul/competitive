#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        unordered_map<string, string> emailName, root;
        unordered_map<string, int> rank;
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> emails;
        vector<vector<string>> res;
        int size = 0;

        function<string(string)> find = [&](string x) {
            if (x != root[x]) {
                root[x] = find(root[x]);
            }
            return root[x];
        };

        function<void(string&, string&)> join = [&](string& x, string& y) {
            auto rootX = find(x), rootY = find(y);

            if (rootX != rootY) {
                if (rank[rootY] > rank[rootX]) {
                    swap(rootX, rootY);
                }
                root[rootY] = rootX;
                rank[rootX] += rank[rootY];
            }
        };

        for (auto a : accounts) {
            auto name = a[0];

            for (auto i = 1; i < a.size(); ++i) {
                emailName.try_emplace(a[i], name);
                root.try_emplace(a[i], a[i]);
                rank.try_emplace(a[i], 1);

                if (i > 1) {
                    join(a[1], a[i]);
                }
            }
        }

        for (auto& [e, _] : root) {
            auto r = find(e);
            emails[r].push(e);
        }

        res.reserve(emails.size());
        for (auto& [k, v] : emails) {
            res.push_back({emailName[k]});
            res.back().reserve(1 + v.size());

            while (!v.empty()) {
                res.back().push_back(v.top());
                v.pop();
            }
        }

        return res;
    }
};

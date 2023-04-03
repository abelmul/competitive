#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

void printAnswer(vector<vector<int>> paths)
{
    cout << paths.size() << "\n";
    for (auto path : paths) {
        cout << path.size() << "\n";
        for (auto p : path) {
            cout << p << " ";
        }
        cout << "\n";
    }

    cout << "\n";
}

void findLeafs(vector<int>& paths, int n, vector<int>& leafs)
{
    leafs.clear();
    unordered_set<int> paths_set =
        unordered_set<int>(paths.begin(), paths.end());

    for (auto i = 0; i < n; ++i) {
        if (paths_set.find(i + 1) == paths_set.end()) {
            leafs.push_back(i + 1);
        }
    }
}

int main()
{
    int t, n, tmp;
    vector<int> p, c, leafs;
    vector<vector<int>> paths;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    for (auto _ = 0; _ < t; ++_) {
        cin >> n;
        p.resize(n);
        paths.clear();

        for (auto i = 0; i < n; ++i) cin >> p[i];

        if (p.size() == 1) {
            printAnswer({{1}});
            continue;
        }

        findLeafs(p, n, leafs);

        for (auto leaf : leafs) {
            c.clear();
            while (p[leaf - 1] != -1 and p[leaf - 1] != leaf) {
                c.push_back(leaf);
                tmp = leaf;
                leaf = p[leaf - 1];
                p[tmp - 1] = -1;
            }

            if (p[leaf - 1] == leaf) {
                c.push_back(p[leaf - 1]);
                p[leaf - 1] = -1;
            }

            reverse(c.begin(), c.end());
            paths.push_back(c);
        }

        printAnswer(paths);
    }

    return 0;
}

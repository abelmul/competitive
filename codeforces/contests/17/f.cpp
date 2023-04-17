#include <bits/stdc++.h>

using namespace std;

/**
 * White-Black Balanced Subtrees
 * https://codeforces.com/gym/438582/problem/F
 * Time - O(n)
 * Space - O(n)
 */

void dfs(int l, const vector<vector<int>>& adjlist, const string& WB,
         unordered_map<int, pair<int, int>>& count)
{
    if (count.find(l) != count.end())  // node is visited
        return;

    int whites = 0, blacks = 0;

    if (WB[l - 1] == 'W') {
        ++whites;
    } else {
        ++blacks;
    }

    for (auto c : adjlist[l - 1]) {
        dfs(c, adjlist, WB, count);

        whites += count[c].first;
        blacks += count[c].second;
    }

    count[l] = make_pair(whites, blacks);
}

int main()
{
    int t, n, res, input;

    string WB;
    vector<vector<int>> adjlist;
    unordered_map<int, pair<int, int>> count;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    for (auto _ = 0; _ < t; ++_) {
        res = 0;
        cin >> n;

        adjlist.resize(n);

        for (auto i = 1; i < n; ++i) {
            cin >> input;
            adjlist[input - 1].push_back(i + 1);
        }

        cin >> WB;

        dfs(1, adjlist, WB, count);

        for (auto& [_, v] : count) {
            if (v.first == v.second) {
                res += 1;
            }
        }

        cout << res << "\n";

        adjlist.clear();
        count.clear();
    }

    return 0;
}

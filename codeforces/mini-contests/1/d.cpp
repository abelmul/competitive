#include <bits/stdc++.h>

using namespace std;

/**
 * PolandBall and Forest
 *
 * https://codeforces.com/gym/444273/problem/D
 *
 * Time - O(n^2)
 * Space - O(n)
 */

void dfs(const vector<int>& p, int i, unordered_set<int>& visited)
{
    if (visited.find(i + 1) != visited.end())
        return;

    visited.insert(i + 1);

    dfs(p, p[i] - 1, visited);

    for (auto j = 0; j < p.size(); ++j) {
        if (p[j] == i + 1) {
            dfs(p, j, visited);
        }
    }
}

int main()
{
    int n;
    vector<int> p;
    unordered_set<int> visited;

    int res = 0;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    p.resize(n);

    for (auto i = 0; i < n; ++i) cin >> p[i];

    for (auto i = 0; i < n; ++i) {
        if (visited.find(i + 1) == visited.end()) {
            dfs(p, i, visited);
            ++res;
        }
    }

    cout << res << "\n";

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

/**
 * Bakery
 * https://codeforces.com/gym/451334/problem/B
 *
 * Time - O(n + k)
 * Space - O(n)
 */

typedef pair<int, int> pii;
int main()
{
    int n, m, k;
    int u, v, l;

    unordered_map<int, vector<pii>> adjList;
    unordered_set<int> a;
    priority_queue<pii, vector<pii>, greater<pii>> queue;

    int res = -1;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    for (auto i = 0; i < m; ++i) {
        cin >> u >> v >> l;
        adjList[u].push_back({v, l});
        adjList[v].push_back({u, l});
    }

    for (auto i = 0; i < k; ++i) {
        cin >> u;
        a.insert(u);
    }

    for (auto i : a) {
        for (auto j : adjList[i]) {
            if (a.find(j.first) == a.end()) {
                queue.emplace(j.second, j.first);
            }
        }
    }

    if (!queue.empty()) {
        res = queue.top().first;
    }

    cout << res << "\n";

    return 0;
}

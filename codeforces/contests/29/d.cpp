#include <bits/stdc++.h>

using namespace std;

/**
 * Hierarchy
 * https://codeforces.com/gym/452649/problem/D
 *
 *  Time - O(n)
 *  Space - O(n)
 */

int main()
{
    int n, m;
    int a, b, c;

    vector<int> costs;

    int parents = 0;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (auto i = 0; i < n; ++i) cin >> a;

    costs.resize(n);
    fill(costs.begin(), costs.end(), INT_MAX);

    cin >> m;
    for (auto i = 0; i < m; ++i) {
        cin >> a >> b >> c;

        if (c < costs[b - 1]) {
            costs[b - 1] = c;
        }
    }

    for (auto i = 0; i < n; ++i) {
        if (costs[i] == INT_MAX) {
            ++parents;
            costs[i] = 0;
        }
    }

    if (parents > 1) {
        cout << -1 << "\n";
    } else {
        cout << reduce(costs.begin(), costs.end()) << "\n";
    }

    return 0;
}

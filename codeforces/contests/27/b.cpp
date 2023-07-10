#include <bits/stdc++.h>

using namespace std;

/**
 * Benches
 * https://codeforces.com/gym/450159/problem/B
 *
 * Time - O(n)
 * Space - O(1)
 */

int main()
{
    int n, m;

    int a, mx = 0, mn;
    priority_queue<int, vector<int>, greater<int>> queue;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (auto i = 0; i < n; ++i) {
        cin >> a;
        mx = max(mx, a);
        queue.push(a);
    }

    for (auto i = 0; i < m; ++i) {
        a = queue.top() + 1;
        queue.pop();
        queue.push(a);
    }

    while (!queue.empty()) {
        mn = queue.top();
        queue.pop();
    }

    cout << mn << " " << mx + m << "\n";

    return 0;
}

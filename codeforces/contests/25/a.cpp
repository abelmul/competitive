#include <bits/stdc++.h>

using namespace std;

/**
 * Koxia and Whiteboards
 * https://codeforces.com/gym/447850/problem/A
 *
 * Time - O(m + log(n))
 * Space - O(1)
 */

int main()
{
    int t, n, m;

    int tmp;
    priority_queue<int, vector<int>, greater<int>> a;
    vector<int> b;

    long long res;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> m;

        b.resize(m);
        for (auto i = 0; i < n; ++i) {
            cin >> tmp;
            a.push(tmp);
        }

        for (auto i = 0; i < m; ++i) cin >> b[i];

        for (auto i = 0; i < m; ++i) {
            a.pop();
            a.push(b[i]);
        }

        res = 0;

        while (!a.empty()) {
            res += a.top();
            a.pop();
        }

        cout << res << "\n";

        a = priority_queue<int, vector<int>, greater<int>>();
        b.clear();
    }

    return 0;
}

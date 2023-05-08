#include <bits/stdc++.h>

using namespace std;

/**
 * Maximal And
 *
 * https://codeforces.com/gym/442062/problem/D
 *
 * Time - O(n)
 * Space - O(1)
 */

int main()
{
    int t, n, k;
    int count;
    int res;

    vector<int> a;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    for (auto _ = 0; _ < t; ++_) {
        res = 0;

        cin >> n >> k;

        a.resize(n);
        for (auto i = 0; i < n; ++i) cin >> a[i];

        for (auto i = 30; i >= 0; --i) {
            count = 0;
            for (auto c : a) {
                count += (bool)(c & (1 << i));
            }

            if (n - count <= k) {
                k -= n - count;
                count = n;
            }

            if (count == n) {
                res |= (1 << i);
            }
        }

        cout << res << "\n";
    }

    return 0;
}

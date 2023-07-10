
#include <bits/stdc++.h>

using namespace std;

/**
 * Eating Queries
 * https://codeforces.com/gym/450159/problem/C
 *
 * Time - O(nlogn)
 * Space - O(1)
 */

int main()
{
    int t, n, q;

    vector<int> a;

    int x, res;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> q;

        a.resize(n);
        for (auto i = 0; i < n; ++i) cin >> a[i];

        sort(a.rbegin(), a.rend());

        for (auto i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }

        for (auto i = 0; i < q; ++i) {
            cin >> x;

            res = upper_bound(a.begin(), a.end(), x) - a.begin();

            if (res > 0 && a[res - 1] == x) {
                --res;
            }

            cout << (res >= n ? -1 : res + 1) << "\n";
        }
    }

    return 0;
}

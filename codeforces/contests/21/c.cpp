#include <bits/stdc++.h>

using namespace std;

/**
 * XOR Mixup
 * https://codeforces.com/gym/443056/problem/C
 *
 * Time - O(n^2)
 * Space - O(1)
 */

int main()
{
    int t, n, res;
    vector<int> a;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    for (auto _ = 0; _ < t; ++_) {
        cin >> n;

        a.resize(n);
        for (auto i = 0; i < n; ++i) cin >> a[i];

        /**
         * because
         * a[0] ^ a[1] ^ ...a[n - 1] = 0
         * implies
         * a[0] ^ a[1] ^ ...a[n-1] ^ a[n - 1] = a[0] ^ a[1] ^ ...a[n-2] = a[n - 1]
         */
        cout << a[0] << "\n";
    }

    return 0;
}

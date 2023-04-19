#include <bits/stdc++.h>

using namespace std;

/**
 * A2SV Verses
 *
 * https://codeforces.com/gym/433716/problem/C
 *
 * Time - O(n)
 * Space - O(1)
 */

int main()
{
    int n, start, end;
    int sum1 = 0, l1 = 0, sum2 = 0, l2 = 0;

    vector<int> a;

    int res = 0;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> start >> end;

    a.resize(n);

    for (auto i = 0; i < n; ++i) cin >> a[i];

    for (auto r = 0; r < n; ++r) {
        sum1 += a[r];
        sum2 += a[r];

        while (sum1 > end) {
            // get index where sum <= end
            sum1 -= a[l1];
            l1 += 1;
        }

        while (sum2 > start - 1) {
            // get index where sum <= start - 1
            sum2 -= a[l2];
            l2 += 1;
        }

        /*
         * res += r - l1 + 1
         * res -= r - l2 + 1
         */

        res += l2 - l1;
    }

    cout << res << "\n";
    return 0;
}

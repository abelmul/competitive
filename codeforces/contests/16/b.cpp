#include <bits/stdc++.h>

using namespace std;

/**
 * Equal Rectangles
 * https://codeforces.com/gym/437545/problem/B
 *
 * Time - O(nlog(n))
 * Space - O(1)
 */

int main()
{
    int q, n;
    vector<int> a;

    int l, r, area;

    string res;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> q;

    for (auto i = 0; i < q; ++i) {
        cin >> n;

        a.resize(4 * n);
        for (auto _ = 0; _ < 4 * n; ++_) cin >> a[_];

        sort(a.begin(), a.end());

        l = 0;
        r = (4 * n) - 1;

        res = "NO\n";

        // calculate area
        if (a[l] == a[l + 1] && a[r] == a[r - 1]) {
            res = "YES\n";

            area = a[l] * a[r];
            l += 2;
            r -= 2;

            for (auto _ = 0; _ < n - 1; ++_) {
                if (a[l] != a[l + 1] || a[r] != a[r - 1] || a[r] * a[l] != area) {
                    res = "NO\n";
                    break;
                }
                l += 2;
                r -= 2;
            }
        }
        cout << res;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

/**
 * Kefa and First Steps
 * https://codeforces.com/gym/437545/problem/A
 * Time - O(n)
 * Space - O(1)
 */

int main()
{
    int n;
    vector<int> a;

    int r, l = 0;
    int res = 1;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    a.resize(n);
    for (auto i = 0; i < n; ++i) cin >> a[i];

    for (r = 1; r < n; ++r) {
        if (a[r] < a[r - 1]) {
            res = max(res, r - l);
            l = r;
        }
    }

    res = max(res, r - l);

    cout << res << "\n";

    return 0;
}

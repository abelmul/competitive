#include <bits/stdc++.h>

using namespace std;

/**
 * Min Or Sum
 * https://codeforces.com/gym/442062/problem/C
 *
 * Time - O(n)
 * Space - O(1)
 */

int main()
{
    int t, n;
    vector<int> a;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    for (auto _ = 0; _ < t; ++_) {
        cin >> n;
        a.resize(n);

        for (auto i = 0; i < n; ++i) cin >> a[i];

        cout << accumulate(a.begin(), a.end(), 0, [](int a, int b) { return a | b; }) << "\n";
    }

    return 0;
}

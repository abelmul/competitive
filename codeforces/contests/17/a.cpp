#include <bits/stdc++.h>

using namespace std;

/**
 * Game Outcome
 * https://codeforces.com/gym/438582/problem/A
 * Time - O(n^2)
 * Space - O(n)
*/

int main()
{
    vector<int> row_sum;
    vector<int> column_sum;

    int n, a, res = 0;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    row_sum.resize(n);
    column_sum.resize(n);

    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < n; ++j) {
            cin >> a;
            row_sum[i] += a;
            column_sum[j] += a;
        }
    }

    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < n; ++j) {
            if (column_sum[j] > row_sum[i]) {
                res += 1;
            }
        }
    }

    cout << res << "\n";

    return 0;
}

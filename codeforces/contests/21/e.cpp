#include <bits/stdc++.h>

using namespace std;

/**
 * And It's Non-Zero
 *
 * https://codeforces.com/gym/443056/problem/E
 *
 * Time - O(n)
 * Space - O(n)
 */

vector<vector<int>> calculatePresum()
{
    vector<vector<int>> presum(200001, vector<int>(20));

    for (int i = 1; i < 200001; ++i) {
        for (int j = 0; j < 20; ++j) {
            presum[i][j] = presum[i - 1][j];
            if (i & (1 << j)) {
                presum[i][j]++;
            }
        }
    }

    return presum;
}

int main()
{
    int t, l, r;

    int res;
    vector<vector<int>> presum;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    presum = calculatePresum();

    while (t--) {
        cin >> l >> r;
        res = 0;
        for (auto j = 0; j < 20; ++j) {
            res = max(res, presum[r][j] - presum[l - 1][j]);
        }

        cout << r - l + 1 - res << "\n";
    }

    return 0;
}

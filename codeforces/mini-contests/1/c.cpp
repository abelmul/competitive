#include <bits/stdc++.h>

using namespace std;

/**
 * Fox And Snake
 *
 * https://codeforces.com/gym/444273/problem/C
 *
 * Time - O(n)
 * Space - O(m)
 */

int main()
{
    int n, m;
    string res;

    bool fill_all = true, fill_at_start = false;
    char f;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    res.resize(m);
    for (auto i = 0; i < n; ++i) {
        f = fill_all ? '#' : '.';
        fill(res.begin(), res.end(), f);

        if (!fill_all) {
            if (fill_at_start) {
                res[0] = '#';
            } else {
                res[m - 1] = '#';
            }

            fill_at_start = !fill_at_start;
        }

        fill_all = !fill_all;

        cout << res << "\n";
    }

    return 0;
}

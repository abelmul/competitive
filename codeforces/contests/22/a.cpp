#include <bits/stdc++.h>

using namespace std;

/**
 * The Way to Home
 * https://codeforces.com/gym/445680/A
 *
 * Time - O(n)
 * Space - O(1)
 */

int main()
{
    int n, d;
    string s;

    int res = 0, i = 0;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> d;
    cin >> s;

    while (i < n) {
        int j = min(i + d, n - 1);
        while (s[j] != '1' && j > i) {
            --j;
        }

        if (s[j] == '1' && j > i) {
            ++res;
            i = j;
        } else {
            break;
        }
    }

    if (i == n - 1) {
        cout << res;
    } else {
        cout << -1;
    }

    cout << "\n";

    return 0;
}

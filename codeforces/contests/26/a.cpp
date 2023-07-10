#include <bits/stdc++.h>

using namespace std;

/**
 * Vanya and Fence
 * https://codeforces.com/gym/449131/problem/A
 *
 * Time - O(n)
 * Space - O(1)
 */

int main()
{
    int n, h;

    int a;

    int res;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> h;

    res = n;

    for (auto i = 0; i < n; ++i) {
        cin >> a;
        if (a > h) {
            ++res;
        }
    }

    cout << res << endl;

    return 0;
}

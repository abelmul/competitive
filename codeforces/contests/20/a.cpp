#include <bits/stdc++.h>

using namespace std;

/**
 * Factorize N + M
 * https://codeforces.com/gym/442062/problem/B
 * 
 * Time - O(1)
 * Space - O(1)
*/

int main()
{
    int t, n;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    for (auto _ = 0; _ < t; ++_) {
        cin >> n;

        if (n == 2) {
            cout << 2;
        } else {
            cout << 3;
        }

        cout << "\n";
    }

    return 0;
}

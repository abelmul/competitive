#include <bits/stdc++.h>

using namespace std;

/**
 * HQ9+
 * https://codeforces.com/gym/450159/problem/A
 *
 * Time - O(n)
 * Space - O(1)
 */

int main()
{
    string s;
    bool result = false;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;

    for (auto c : s) {
        if (c == 'H' || c == 'Q' || c == '9') {
            result = true;
            break;
        }
    }

    cout << (result ? "YES" : "NO") << "\n";

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

/**
 * Magic Numbers
 *
 * https://codeforces.com/gym/444273/problem/B
 *
 * Time - O(n)
 * Space - O(1)
 */

bool backtrack(const string& n, int l)
{
    if (l >= n.size()) {
        return true;
    }

    if (n[l] == '1') {
        if (backtrack(n, l + 1)) {
            return true;
        }

        ++l;
        if (l < n.size() && n[l] == '4') {
            if (backtrack(n, l + 1)) {
                return true;
            }

            ++l;
            if (l < n.size() && n[l] == '4' && backtrack(n, l + 1)) {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    string n;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    if (backtrack(n, 0)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    cout << "\n";

    return 0;
}

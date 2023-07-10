#include <bits/stdc++.h>

using namespace std;

/**
 * Pangram
 * https://codeforces.com/gym/451334/problem/A
 *
 * Time - O(1)
 * Space - O(1)
 */

int main()
{
    unordered_set<char> letters;
    int n;
    string s;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> s;

    if (n >= 26) {
        for (auto c : s) {
            letters.insert(tolower(c));
        }
    }

    cout << (letters.size() == 26 ? " YES" : "NO") << "\n";

    return 0;
}

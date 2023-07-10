#include <bits/stdc++.h>

using namespace std;

/**
 * Misha and Changing Handles
 * https://codeforces.com/gym/452649/problem/B
 *
 * Time - O(n + q)
 * Space - O(n)
 */

int main()
{
    int q;
    string o, n;
    unordered_map<string, string> handles;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> q;

    while (q--) {
        cin >> o >> n;

        if (handles.find(o) == handles.end()) {
            handles[n] = o;
        } else {
            handles[n] = handles[o];
            handles.erase(o);
        }
    }
    cout << handles.size() << endl;

    for (auto &[k, v] : handles) {
        cout << v << " " << k << "\n";
    }
    return 0;
}

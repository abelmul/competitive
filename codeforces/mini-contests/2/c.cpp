#include <bits/stdc++.h>

using namespace std;

/**
 * Two Buttons
 * https://codeforces.com/gym/445382/problem/B
 *
 * Time - O(nlog(n))
 * Space - O(1)
 */

int main()
{
    int n;
    vector<int> a;
    string rule;

    unordered_map<int, unordered_set<int>> connected;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    a.resize(n);

    for (auto i = 0; i < n; ++i) cin >> a[i];

    cin >> rule;

    int j, i = 0;

    while (i < n - 1) {
        if (rule[i] == '1') {
            j = i;
            while (rule[j] == '1') {
                ++j;
            }

            sort(a.begin() + i, a.begin() + j + 1);
            i = j + 1;
        } else {
            ++i;
        }
    }

    bool isSorted = true;
    for (auto i = 1; i < n; ++i) {
        if (a[i - 1] > a[i]) {
            isSorted = false;
        }
    }

    if (isSorted) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << "\n";

    return 0;
}

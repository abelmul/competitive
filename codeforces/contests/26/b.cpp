#include <bits/stdc++.h>

using namespace std;

/**
 * Bus of Characters
 * https://codeforces.com/gym/449131/problem/B
 *
 * Time - O(n)
 * Space - O(1)
 */

int main()
{
    int n, w;

    char p;

    pair<int, int> row;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> unfilled;
    priority_queue<pair<int, int>> filled;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (auto i = 0; i < n; ++i) {
        cin >> w;

        unfilled.emplace(w, i);
    }

    for (auto i = 0; i < 2 * n; ++i) {
        cin >> p;

        if (p == '0') {
            row = unfilled.top();
            unfilled.pop();

            cout << row.second + 1 << " ";

            filled.push(row);
        } else {
            row = filled.top();
            filled.pop();

            cout << row.second + 1 << " ";
        }
    }

    cout << "\n";

    return 0;
}

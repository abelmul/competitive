#include <bits/stdc++.h>

using namespace std;

/**
 * Transformation: from A to B
 *
 * https://codeforces.com/gym/444273/problem/A
 *
 * Time - O(log(n))
 * Space - O(log(n))
 */

bool dfs(long long a, long long b, vector<int>& current)
{
    if (a < 0) {
        return false;
    } else if (a == b) {
        current.push_back(a);
        return true;
    } else if (a < b && (dfs((a * 10) + 1, b, current) || dfs(a * 2, b, current))) {
        current.push_back(a);
        return true;
    }

    return false;
}

int main()
{
    long long a, b;
    vector<int> current;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b;

    if (dfs(a, b, current)) {
        cout << "YES";
        cout << "\n";

        cout << current.size() << "\n";
        for (auto i = current.rbegin(); i != current.rend(); ++i) {
            cout << *i << " ";
        }

        cout << "\n";
    } else {
        cout << "NO"
             << "\n";
    }

    return 0;
}

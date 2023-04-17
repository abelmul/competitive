#include <bits/stdc++.h>

using namespace std;

/**
 * 360 degree's
 * https://codeforces.com/gym/438582/problem/E
 * Time - O(n)
 * Space - O(1)
 */

inline int positive_modulo(int i, int n) { return (i % n + n) % n; }

bool canGetTo360(int n, const vector<int>& angles, int current = 0)
{
    if (n == angles.size())
        return positive_modulo(current, 360) == 0;

    return canGetTo360(n + 1, angles, current + angles[n]) ||
           canGetTo360(n + 1, angles, current - angles[n]);
}

int main()
{
    int n;
    vector<int> angles;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    angles.resize(n);

    for (auto i = 0; i < n; ++i) cin >> angles[i];

    if (canGetTo360(0, angles, 0))
        cout << "YES";
    else
        cout << "NO";

    cout << "\n";

    return 0;
}

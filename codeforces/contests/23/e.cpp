#include <bits/stdc++.h>

using namespace std;

/**
 * Jumping On Walls
 * https://codeforces.com/gym/445680/problem/E
 *
 * Time - O(n)
 * Space - O(1)
 */

int main()
{
    int n, k;

    string walls[2];

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    cin >> walls[0] >> walls[1];

    function<bool(int, int, int)> dfs = [&](int level, int pos, int wall) {
        if (pos >= n)
            return true;

        if (pos < level || walls[wall][pos] != '-')
            return false;

        walls[wall][pos] = 'V';
        ++level;

        return dfs(level, pos + k, !wall) || dfs(level, pos + 1, wall) || dfs(level, pos - 1, wall);
    };

    if (dfs(0, 0, 0)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

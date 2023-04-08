#include <bits/stdc++.h>

using namespace std;

/**
 * Game 23
 * https://codeforces.com/gym/437545/problem/D
 *
 * Time - O(log(n))
 * Space - O(1)
 */

int solve(int n, int m, int moves = 0)
{
    if (n > m) {
        return -1;
    }

    if (n == m) {
        return moves;
    }

    // solve for n * 2
    int n2 = solve(n * 2, m, moves + 1);

    // solve for n * 3
    int n3 = solve(n * 3, m, moves + 1);

    return max(n2, n3);
}

int main()
{
    int n, m;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    cout << solve(n, m) << "\n";

    return 0;
}

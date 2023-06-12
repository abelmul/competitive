#include <bits/stdc++.h>

using namespace std;

/**
 * Ultra-fast Mathematician
 * https://codeforces.com/gym/443056/problem/B
 *
 * Time - O(n)
 * Space - O(n)
 */

int main()
{
    string n, m;
    string res;

    size_t size;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    size = n.size();
    res.resize(size);

    for (auto i = 0; i < size; ++i) {
        res[i] = '0';

        if (n[i] != m[i]) {
            res[i] = '1';
        }
    }

    cout << res << "\n";

    return 0;
}

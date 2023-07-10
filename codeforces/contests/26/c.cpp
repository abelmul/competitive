#include <bits/stdc++.h>

using namespace std;

/**
 * Forever Winter
 *  https://codeforces.com/gym/449131/problem/C
 *
 *  Time - O(n)
 *  Space - O(n)
 */

int main()
{
    int t;

    int n, m;
    int x, y;
    vector<int> indegree;

    int second, root;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> m;

        indegree.resize(n);

        for (auto i = 0; i < m; ++i) {
            cin >> x >> y;
            ++indegree[x - 1];
            ++indegree[y - 1];
        }

        sort(indegree.rbegin(), indegree.rend());

        if (indegree[0] == indegree[1]) {
            second = indegree[0];

            root = 0;
            for (; indegree[root] == second && indegree[root] > 1; ++root) {}

            if (indegree[root] == 1)
                --root;

            root = indegree[root];
        } else {
            root = indegree[0];
            second = indegree[1];
        }

        cout << root << " " << second - 1 << "\n";

        indegree.clear();
    }

    return 0;
}

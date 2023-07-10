#include <bits/stdc++.h>

using namespace std;

/**
 * Mocha and Diana (Easy Version)
 * https://codeforces.com/gym/452649/problem/E
 *
 * Time - O(n^2)
 * Space - O(m1 + m2)
 */

int find(int* root, int x)
{
    if (x != root[x - 1]) {
        root[x - 1] = find(root, root[x - 1]);
    }

    return root[x - 1];
}

void join(int* root, int* rank, int x, int y)
{
    auto rootX = find(root, x);
    auto rootY = find(root, y);

    if (rootX != rootY) {
        if (rank[rootY - 1] > rank[rootX - 1]) {
            swap(rootX, rootY);
        }

        root[rootY - 1] = rootX;
        rank[rootX - 1] += rank[rootY - 1];
    }
}

int main()
{
    int n, m1, m2;
    int u, v;

    int rank1[1000], rank2[1000], root1[1000], root2[1000];

    vector<pair<int, int>> res;

    // init union-find DS
    iota(begin(root1), end(root1), 1);
    iota(begin(root2), end(root2), 1);

    fill(begin(rank1), end(rank1), 1);
    fill(begin(rank2), end(rank2), 1);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m1 >> m2;

    for (auto i = 0; i < m1; ++i) {
        cin >> u >> v;
        join(root1, rank1, u, v);
    }

    for (auto i = 0; i < m2; ++i) {
        cin >> u >> v;
        join(root2, rank2, u, v);
    }

    // brute force since n <= 1000
    for (auto i = 1; i <= n; ++i) {
        for (auto j = i + 1; j <= n; ++j) {
            if (find(root1, i) != find(root1, j) && find(root2, i) != find(root2, j)) {
                join(root1, rank1, i, j);
                join(root2, rank2, i, j);

                res.push_back({i, j});
            }
        }
    }
    cout << res.size() << "\n";
    for (auto r : res) cout << r.first << " " << r.second << "\n";

    return 0;
}

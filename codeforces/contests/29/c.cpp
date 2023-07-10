#include <bits/stdc++.h>

using namespace std;

/**
 * Love Rescue
 * https://codeforces.com/gym/452649/problem/C
 *
 * Time - O(n)
 * Space - O(n)
 */

char find(char* root, char x)
{
    if (x != root[x - 'a']) {
        root[x - 'a'] = find(root, root[x - 'a']);
    }

    return root[x - 'a'];
}

void join(char* root, int* rank, char x, char y)
{
    auto rootX = find(root, x);
    auto rootY = find(root, y);

    if (rootX != rootY) {
        if (rank[rootY - 'a'] > rank[rootX - 'a']) {
            swap(rootX, rootY);
        }

        root[rootY - 'a'] = rootX;
        rank[rootX - 'a'] += rank[rootY - 'a'];
    }
}

int main()
{
    int n;

    string a, b;

    int rank[26];
    char root[26];
    vector<pair<char, char>> res;

    // init union-find DS
    fill(begin(rank), end(rank), 1);
    iota(begin(root), end(root), 'a');

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> a;
    cin >> b;

    for (auto i = 0; i < n; ++i) {
        if (find(root, a[i]) != find(root, b[i])) {
            res.push_back({a[i], b[i]});
            join(root, rank, a[i], b[i]);
        }
    }

    cout << res.size() << "\n";
    for (auto r : res) cout << r.first << " " << r.second << "\n";

    return 0;
}

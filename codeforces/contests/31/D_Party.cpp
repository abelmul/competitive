#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, m;

    int u, v;

    vector<int> root, rank;

    unordered_set<int> disqualified;
    unordered_map<int, int> groups;

    int res = 0;

    ios::sync_with_stdio(false);
    cin.tie(0);

    function<int(int)> find = [&](int x) {
        if (x != root[x]) {
            root[x] = find(root[x]);
        }

        return root[x];
    };

    auto join = [&](int x, int y) {
        auto rootX = find(x), rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootY] > rank[rootX]) {
                swap(rootX, rootY);
            }

            root[rootY] = rootX;
            rank[rootX] += rank[rootY];
        }
    };

    cin >> n;
    cin >> k;

    // init Union find
    root.resize(n);
    rank.resize(n);

    fill(rank.begin(), rank.end(), 1);
    iota(root.begin(), root.end(), 0);

    for (auto _ = 0; _ < k; ++_) {
        cin >> u >> v;
        --u;
        --v;

        join(u, v);
    }

    cin >> m;
    for (auto _ = 0; _ < m; ++_) {
        cin >> u >> v;

        --u;
        --v;

        if (find(u) == find(v)) {
            disqualified.insert(find(u));
        }
    }

    for (auto i = 0; i < n; ++i) {
        auto f = find(i);
        if (disqualified.find(f) == disqualified.end()) {
            ++groups[f];
        }
    }

    for (auto &[_, v] : groups) {
        res = max(res, v);
    }

    cout << res << "\n";

    return 0;
}

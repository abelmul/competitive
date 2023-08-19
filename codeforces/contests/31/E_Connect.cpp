#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int r1, c1;
    int r2, c2;

    vector<string> grid;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> r1 >> c1;
    cin >> r2 >> c2;

    --r1;
    --r2;
    --c1;
    --c2;

    grid.resize(n);
    for (auto i = 0; i < n; ++i) cin >> grid[i];

    // union find
    vector<vector<pair<int, int>>> root(n, vector<pair<int, int>>(n));
    vector<vector<int>> rank(n, vector<int>(n, 1));

    // init
    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < n; ++j) {
            root[i][j] = {i, j};
        }
    }

    function<pair<int, int>(pair<int, int>)> find = [&](pair<int, int> pos) {
        if (pos != root[pos.first][pos.second]) {
            root[pos.first][pos.second] = find(root[pos.first][pos.second]);
        }

        return root[pos.first][pos.second];
    };

    auto join = [&](pair<int, int> x, pair<int, int> y) {
        auto rootX = find(x);
        auto rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootY.first][rootY.second] > rank[rootX.first][rootX.second]) {
                swap(rootY, rootX);
            }

            root[rootY.first][rootY.second] = rootX;
            rank[rootX.first][rootX.second] += rank[rootY.first][rootY.second];
        }
    };

    // bfs queue
    deque<pair<int, int>> queue;
    map<pair<int, int>, pair<int, int>> prev;

    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < n; ++j) {
            if (grid[i][j] == '1')
                continue;

            // go forward
            if (i + 1 < n && grid[i + 1][j] == '0') {
                join({i, j}, {i + 1, j});
            }

            if (j + 1 < n && grid[i][j + 1] == '0') {
                join({i, j}, {i, j + 1});
            }
            if (find({r1, c1}) == find({i, j})) {
                queue.push_back({i, j});
                prev[{i, j}] = {i, j};
            }
        }
    }

    // shortest path
    pair<int, int> res, source;
    while (!queue.empty()) {
        auto &[i, j] = queue.front();
        queue.pop_front();

        if (find({i, j}) == find({r2, c2})) {
            res = {i, j};
            break;
        }

        if (i + 1 < n && prev.find({i + 1, j}) == prev.end()) {
            queue.push_back({i + 1, j});
            prev[{i + 1, j}] = {i, j};
        }
        if (i - 1 >= 0 && prev.find({i - 1, j}) == prev.end()) {
            queue.push_back({i - 1, j});
            prev[{i - 1, j}] = {i, j};
        }
        if (j + 1 < n && prev.find({i, j + 1}) == prev.end()) {
            queue.push_back({i, j + 1});
            prev[{i, j + 1}] = {i, j};
        }
        if (j - 1 >= 0 && prev.find({i, j - 1}) == prev.end()) {
            queue.push_back({i, j - 1});
            prev[{i, j - 1}] = {i, j};
        }
    }

    source = res;
    while (source != prev[source]) {
        source = prev[source];
    }

    cout << pow((source.first - res.first), 2) + pow((source.second - res.second), 2) << "\n";

    return 0;
}

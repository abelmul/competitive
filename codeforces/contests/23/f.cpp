#include <bits/stdc++.h>

using namespace std;

/**
 * The Two Routes
 * https://codeforces.com/gym/445680/problem/F
 *
 * Time - O(n + m)
 * Space - O(n)
 */

vector<int> bfsTrain(unordered_map<int, unordered_set<int>>& railways, int n, int i)
{
    vector<int> res;

    deque<int> queue;
    unordered_map<int, int> prev;

    queue.push_back(i);
    prev[i] = -1;

    while (!queue.empty()) {
        i = queue.front();
        queue.pop_front();

        if (i == n) {
            break;
        }

        for (auto j : railways[i]) {
            if (prev.find(j) == prev.end()) {
                prev[j] = i;
                queue.push_back(j);
            }
        }
    }

    if (prev.find(n) != prev.end()) {
        while (n != -1) {
            res.push_back(n);
            n = prev[n];
        }
    }

    return res;
}

vector<int> bfsBus(unordered_map<int, unordered_set<int>>& railways, int n, int i)
{
    vector<int> res;

    deque<int> queue;
    unordered_map<int, int> prev;

    queue.push_back(i);
    prev[i] = -1;

    while (!queue.empty()) {
        i = queue.front();
        queue.pop_front();

        if (i == n) {
            break;
        }

        for (auto j = 1; j <= n; ++j) {
            if (railways[i].find(j) == railways[i].end() && prev.find(j) == prev.end()) {
                prev[j] = i;
                queue.push_back(j);
            }
        }
    }

    if (prev.find(n) != prev.end()) {
        while (n != -1) {
            res.push_back(n);
            n = prev[n];
        }
    }

    return res;
}

int calcMin(vector<int>& train, vector<int>& bus)
{
    if (train.empty() || bus.empty()) {
        return -1;
    }

    auto ts = train.size(), bs = bus.size();
    int res = 0;

    int i = ts - 2, j = bs - 2;

    while (i >= 0 && j >= 0) {
        if (train[i] == bus[j]) {
            ++res;
            --i;
        } else {
            --i;
            --j;
        }
        ++res;
    }

    while (i >= 0) {
        ++res;
        --i;
    }

    while (j >= 0) {
        ++res;
        --j;
    }

    return res;
}

int main()
{
    int n, m;
    int u, v;
    unordered_map<int, unordered_set<int>> railways;

    vector<int> train, bus;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (auto i = 0; i < m; ++i) {
        cin >> u >> v;

        railways[u].insert(v);
        railways[v].insert(u);
    }

    train = bfsTrain(railways, n, 1);
    bus = bfsBus(railways, n, 1);

    cout << calcMin(train, bus) << "\n";

    return 0;
}

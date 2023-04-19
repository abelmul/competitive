#include <bits/stdc++.h>

using namespace std;

/**
 * Lightest Bus
 *
 * https://codeforces.com/gym/433716/problem/D
 *
 * Recursive
 *
 * Time - O(n)
 * Space - O(1)
 *
 * Iterative
 *
 * Time - O(V+E)
 * Space - O(n)
 */

int solve(const vector<int>& presum, int l, unordered_map<int, int>& memo)
{
    // recursive using memoization
    if (memo.find(l) == memo.end()) {
        int size = presum.size();

        if (l >= size - 1) {
            return INT_MAX;
        }

        int min12 = min(size - 1, l + 12);
        int min18 = min(size - 1, l + 18);

        auto res = min(min(presum[min12] - presum[l], presum[min18] - presum[l]),
                       min(solve(presum, l + 12, memo), solve(presum, l + 18, memo)));

        memo[l] = res;
    }

    return memo[l];
}

int dfs(const vector<int>& presum)
{
    // depth first search assuming graph

    int size = presum.size();

    stack<int> index;
    set<int> visited;
    int i;

    int minimum_size = INT_MAX;

    index.push(0);

    while (!index.empty()) {
        i = index.top();
        index.pop();

        if (i < size - 1 && visited.find(i) == visited.end()) {
            minimum_size = min(minimum_size, presum[min(size - 1, i + 12)] - presum[i]);
            minimum_size = min(minimum_size, presum[min(size - 1, i + 18)] - presum[i]);

            index.push(i + 12);
            index.push(i + 18);

            visited.insert(i);
        }
    }

    return minimum_size;
}

int main()
{
    int t, n;

    vector<int> presum;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    for (auto _ = 0; _ < t; ++_) {
        cin >> n;

        presum.resize(n + 1);

        presum[0] = 0;

        for (auto i = 0; i < n; ++i) {
            cin >> presum[i + 1];
            presum[i + 1] += presum[i];
        }

        cout << dfs(presum) << "\n";
    }

    return 0;
}

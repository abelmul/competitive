#include <bits/stdc++.h>

using namespace std;

/**
 * Book
 * https://codeforces.com/gym/451334/problem/D
 *
 * Time - O(V+E)
 * Space - O(V)
 */

int main()
{
    int t, n;

    int u, res;

    unordered_map<int, vector<int>> adjList;
    vector<int> indegree;
    vector<int> sorted;

    function<bool(int, int)> compare = [&](int lhs, int rhs) {
        if (!sorted.empty()) {
            if (lhs >= sorted.back() && rhs < sorted.back()) {
                return false;
            } else if (lhs < sorted.back() && rhs >= sorted.back()) {
                return true;
            }
        }

        return lhs > rhs;
    };
    priority_queue<int, vector<int>, decltype(compare)> queue(compare);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> n;

        indegree.resize(n);
        for (auto i = 0; i < n; ++i) {
            cin >> indegree[i];

            if (indegree[i] == 0) {
                queue.push(i + 1);
            }

            for (auto j = 0; j < indegree[i]; ++j) {
                cin >> u;
                adjList[u].push_back(i + 1);
            }
        }

        // toposort
        sorted.reserve(n);
        while (!queue.empty()) {
            auto t = queue.top();
            queue.pop();

            sorted.push_back(t);

            for (auto i : adjList[t]) {
                if (--indegree[i - 1] == 0) {
                    queue.push(i);
                }
            }
        }

        if (sorted.size() == n) {
            res = 1;
            for (auto i = 1; i < n; ++i) {
                if (sorted[i] < sorted[i - 1]) {
                    ++res;
                }
            }
            cout << res;
        } else {
            cout << -1;
        }

        cout << "\n";

        adjList.clear();
        sorted.clear();
        queue = priority_queue<int, vector<int>, decltype(compare)>(compare);
    }

    return 0;
}

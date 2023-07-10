#include <bits/stdc++.h>

using namespace std;

/**
 * Gardener and Tree
 * https://codeforces.com/gym/451334/problem/C
 *
 * Time - O(V+E)
 * Space -  O(V)
 */

typedef pair<int, int> pii;
int main()
{
    int t;

    int n, k;
    int u, v;

    unordered_map<int, vector<int>> adjList;
    vector<int> indegree;
    deque<pii> queue;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> k;

        indegree.resize(n);
        for (auto i = 0; i < n - 1; ++i) {
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);

            ++indegree[u - 1];
            ++indegree[v - 1];
        }

        for (auto i = 0; i < n; ++i) {
            if (indegree[i] <= 1) {
                queue.emplace_back(i + 1, 0);
            }
        }

        while (!queue.empty()) {
            auto t = queue.front();
            queue.pop_front();

            if (t.second == k) {
                break;
            }

            for (auto j : adjList[t.first]) {
                --indegree[j - 1];
                if (indegree[j - 1] == 1) {
                    queue.emplace_back(j, t.second + 1);
                }
            }
            --n;
        }

        cout << n << "\n";

        adjList.clear();
        queue.clear();
        indegree.clear();
    }

    return 0;
}

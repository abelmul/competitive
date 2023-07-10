#include <bits/stdc++.h>

using namespace std;

/**
 * Lunar New Year and a Wander
 * https://codeforces.com/gym/449131/problem/D
 *
 * Time - O(V+E)
 * Space - o(n)
 */

void bfs(unordered_map<int, set<int>>& adjList, int n, vector<int>& res)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> visited;

    visited.resize(n);

    pq.push(1);
    visited[0] = 1;

    while (!pq.empty()) {
        auto i = pq.top();
        pq.pop();

        res.push_back(i);

        for (auto j : adjList[i]) {
            if (!visited[j - 1]) {
                pq.push(j);
                visited[j - 1] = 1;
            }
        }
    }
}

int main()
{
    int n, m;

    int x, y;
    unordered_map<int, set<int>> adjList;

    vector<int> res;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (auto i = 0; i < m; ++i) {
        cin >> x >> y;

        adjList[x].insert(y);
        adjList[y].insert(x);
    }

    bfs(adjList, n, res);

    for (auto r : res) cout << r << " ";
    cout << "\n";

    return 0;
}

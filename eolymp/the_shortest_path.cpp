#include <bits/stdc++.h>

using namespace std;

vector<int> shortestPath(unordered_map<int, vector<int>>& adjList, int start, int end)
{
    vector<int> res;

    deque<int> queue;
    unordered_map<int, int> prev;

    queue.push_back(start);
    prev[start] = -1;

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop_front();

        if (node == end) {
            break;
        }

        for (auto v : adjList[node]) {
            if (prev.find(v) == prev.end()) {
                prev[v] = node;
                queue.push_back(v);
            }
        }
    }

    if (prev.find(end) != prev.end()) {
        while (end != -1) {
            res.push_back(end);
            end = prev[end];
        }
    }

    return res;
}

int main()
{
    int n, m;

    int start, end;
    int a, b;
    unordered_map<int, vector<int>> adjList;

    vector<int> res;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    cin >> start >> end;

    for (auto _ = 0; _ < m; ++_) {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    res = shortestPath(adjList, start, end);

    if (res.size() == 0) {
        cout << -1 << "\n";
    } else {
        cout << res.size() - 1 << "\n";
        for (auto i = res.rbegin(); i != res.rend(); ++i) {
            cout << *i << " ";
        }
        cout << "\n";
    }

    return 0;
}

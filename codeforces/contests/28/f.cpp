#include <bits/stdc++.h>

using namespace std;

/**
 * Fox And Names
 * https://codeforces.com/gym/451334/problem/F
 *
 * Time - O(V+E)
 * Space - O(n)
 */

int main()
{
    int n;

    vector<string> names;

    int indegree[26] = {0};
    // priority_queue<int, vector<int>, greater<int>> queue;
    deque<int> queue;
    vector<int> adjList[26];
    string res;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    names.resize(n);
    for (auto i = 0; i < n; ++i) cin >> names[i];

    // create adj list
    for (auto i = 1; i < n; ++i) {
        if (names[i] == names[i - 1]) {
            continue;
        }
        auto j = 0;
        auto size = min(names[i - 1].size(), names[i].size());

        while (j < size && names[i - 1][j] == names[i][j]) {
            ++j;
        }
        if (j < size) {
            adjList[names[i - 1][j] - 'a'].push_back(names[i][j] - 'a');
            ++indegree[names[i][j] - 'a'];
        } else if (names[i - 1].size() > names[i].size()) {
            fill(begin(indegree), end(indegree), 1);
            break;
        }
    }

    for (auto i = 0; i < 26; ++i) {
        if (indegree[i] == 0) {
            queue.push_back(i);
        }
    }

    // topological sorting
    res.reserve(26);
    while (!queue.empty()) {
        auto t = queue.front();
        queue.pop_front();

        res.push_back(t + 'a');

        for (auto i : adjList[t]) {
            --indegree[i];
            if (indegree[i] == 0) {
                queue.push_back(i);
            }
        }
    }

    if (res.size() == 26) {
        cout << res;
    } else {
        cout << "Impossible";
    }
    cout << "\n";

    return 0;
}

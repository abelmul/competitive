#include <bits/stdc++.h>

using namespace std;

/**
 * Computer Game
 * https://codeforces.com/gym/445382/problem/A
 *
 * Time - O(n)
 * Space - O(n)
 */

const pair<int, int> dirs[] = {
    {-1, 1}, {0, 1}, {1, 1}, {-1, 0}, {1, 0}, {-1, -1}, {0, -1}, {1, -1},
};

bool hasPath(int n, vector<string>& a)
{
    deque<pair<int, int>> queue;
    set<pair<int, int>> visited;

    pair<int, int> current;
    int r, c;

    queue.push_back({0, 0});

    while (!queue.empty()) {
        current = queue.front();
        queue.pop_front();

        if (visited.find(current) != visited.end())
            continue;

        if (current.first == 1 && current.second == n - 1)
            return true;

        visited.insert(current);

        for (auto d : dirs) {
            r = current.first + d.first;
            c = current.second + d.second;

            if (r >= 0 && r < 2 && c >= 0 && c < n && a[r][c] == '0') {
                queue.push_back({r, c});
            }
        }
    }

    return false;
}

int main()
{
    int t, n;
    vector<string> a;
    string rule;

    ios::sync_with_stdio(false);
    cin.tie(0);

    a.resize(2);
    cin >> t;

    while (t--) {
        cin >> n;
        cin >> a[0];
        cin >> a[1];

        if (hasPath(n, a)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << "\n";
    }

    return 0;
}

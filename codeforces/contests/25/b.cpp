#include <bits/stdc++.h>

using namespace std;

/**
 * Productive Meeting
 * https://codeforces.com/gym/447850/problem/B
 *
 * Time - O(log(n))
 * Space - O(n)
*/

void solve(priority_queue<pair<int, int>>& pq)
{
    vector<pair<int, int>> res;

    pair<int, int> a = {0, 0}, b = {0, 0};

    while (pq.size() > 1) {
        a = pq.top();
        pq.pop();

        b = pq.top();
        pq.pop();

        if (b.first && a.first) {
            res.push_back({a.second + 1, b.second + 1});

            --b.first;
            --a.first;
        }

        if (a.first) {
            pq.push(a);
        }

        if (b.first) {
            pq.push(b);
        }
    }

    cout << res.size() << "\n";
    for (auto r : res) cout << r.first << " " << r.second << "\n";
}

int main()
{
    int t, n;

    int a;
    priority_queue<pair<int, int>> pq;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> n;

        for (auto i = 0; i < n; ++i) {
            cin >> a;

            pq.push({a, i});
        }

        solve(pq);

        pq = priority_queue<pair<int, int>>();
    }

    return 0;
}

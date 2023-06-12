#include <bits/stdc++.h>

using namespace std;

/**
 * Network Topology 
 * https://codeforces.com/gym/447850/problem/C
 *
 * Time - O(nlog(n))
 * Space - O(1)
*/

int main()
{
    int n, m;
    int a, b;

    vector<int> in_degree;

    bool is_known_topology = false;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    in_degree.resize(n);

    for (auto _ = 0; _ < m; ++_) {
        cin >> a >> b;

        ++in_degree[a - 1];
        ++in_degree[b - 1];
    }

    sort(in_degree.rbegin(), in_degree.rend());

    if (in_degree.front() == n - 1) {
        is_known_topology = true;
        if (in_degree.back() != 1 || in_degree[1] != 1) {
            is_known_topology = false;
        } else {
            cout << "star ";
        }
    } else if (in_degree.front() == 2) {
        if (in_degree.back() == 1 && in_degree.rbegin()[1] == 1 && in_degree.rbegin()[2] == 2) {
            is_known_topology = true;
            cout << "bus ";
        } else if (in_degree.back() == 2) {
            is_known_topology = true;
            cout << "ring ";
        }
    }

    if (!is_known_topology) {
        cout << "unknown ";
    }

    cout << "topology\n";

    return 0;
}

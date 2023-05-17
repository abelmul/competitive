#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    int op, from, to;

    vector<vector<int>> edge_list;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> k;

    edge_list.resize(n);

    for (auto i = 0; i < k; ++i) {
        cin >> op;

        if (op == 1) {
            // add edge
            cin >> from >> to;
            edge_list[from - 1].push_back(to);
            edge_list[to - 1].push_back(from);
        } else {
            // vertex
            cin >> from;
            for (auto i = 0; i < edge_list[from - 1].size(); ++i)
                cout << edge_list[from - 1][i] << " ";
            cout << "\n";
        }
    }

    return 0;
}

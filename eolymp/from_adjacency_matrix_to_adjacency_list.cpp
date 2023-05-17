#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int input, size;
    vector<vector<int>> adj_list;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    adj_list.resize(n);

    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < n; ++j) {
            cin >> input;
            if (input) {
                adj_list[i].push_back(j + 1);
            }
        }
    }

    for (auto i = 0; i < n; ++i) {
        size = adj_list[i].size();

        sort(adj_list[i].begin(), adj_list[i].end());

        cout << size;
        for (auto j = 0; j < size; ++j) cout << " " << adj_list[i][j];
        cout << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<int> sources, sinks;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    vector<vector<int>> input(n, vector<int>(n));

    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < n; ++j) cin >> input[i][j];
    }

    for (auto i = 0; i < n; ++i) {
        bool isSource = true, isSink = true;
        for (auto j = 0; j < n; ++j) {
            if (input[i][j] == 1) {
                isSink = false;
            }

            if (input[j][i] == 1) {
                isSource = false;
            }
        }

        if (isSink) {
            sinks.push_back(i);
        }

        if (isSource) {
            sources.push_back(i);
        }
    }

    cout << sources.size();
    for (auto s : sources) cout << " " << s + 1;
    cout << "\n";

    cout << sinks.size();
    for (auto s : sinks) cout << " " << s + 1;
    cout << "\n";

    return 0;
}

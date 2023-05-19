#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int input;

    int res = 0;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < n; ++j) {
            cin >> input;
            res += input;
        }
    }

    cout << res / 2 << "\n";

    return 0;
}

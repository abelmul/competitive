#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, s;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> a;
    cin >> s;

    // reverse sort s
    sort(s.rbegin(), s.rend());

    auto n = a.size(), m = s.size();

    int j = 0;
    for (auto i = 0, j = 0; i < n && j < m; ++i) {
        if (a[i] < s[j]) {
            a[i] = s[j++];
        }
    }

    cout << a << "\n";

    return 0;
}

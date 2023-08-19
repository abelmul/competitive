#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<pair<int, int>> a;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    a.resize(n);
    for (auto i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    if (n > 1 && a[0].first == a[1].first) {
        cout << "Still Rozdil";
    } else {
        cout << a[0].second + 1;
    }

    cout << "\n";

    return 0;
}

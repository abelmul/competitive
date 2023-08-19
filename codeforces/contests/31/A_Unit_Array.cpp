#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;

    vector<int> a;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;

        a.resize(n);
        for(auto i = 0; i < n; ++i) cin >> a[i];

        sort(a.begin(), a.end());

    }

    return 0;
}

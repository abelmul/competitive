#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;

    vector<int> a;

    int res = 0, l = 0, sum = 0;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> t;

    a.resize(n);

    for(auto i = 0; i < n;++i) cin >> a[i];

    for(auto i = 0; i < n; ++i) {
        sum += a[i];

        while(sum > t) {
            sum -= a[l];
            ++l;
        }

        res = max(res, i - l + 1);
    }

    cout << res << "\n";

    return 0;
}

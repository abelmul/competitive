#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, k;

    vector<int> a;
    int sum = 0, max_ops, min_ops;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while(t--) {
        cin >> n >> k;

        for(auto i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        min_ops = 0;
        max_ops = sum - k;


    }

    return 0;
}

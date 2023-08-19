#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long solve(const vector<ll>& a, ll mx)
{
    long long res = 0;

    vector<ll> counter(mx + 1, 0);
    vector<long long> memo(mx + 1, -1);

    for (auto i : a) {
        ++counter[i];
    }

    function<long long(ll)> dp = [&](ll i) {
        if (i > mx) {
            return static_cast<long long>(0);
        }

        if (memo[i] == -1) {
            // pick i
            memo[i] = max(i * counter[i] + dp(i + 2), dp(i + 1));
        }

        return memo[i];
    };

    return max(dp(0), dp(1));
}

int main()
{
    int n;

    vector<ll> a;
    ll mx = 0;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    a.resize(n);
    for (auto i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    cout << solve(a, mx) << "\n";

    return 0;
}

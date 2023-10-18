#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(vector<ll>& a) {
    ll sum = accumulate(a.begin(), a.end(), 0);

    vector<ll> memo(a.size() + 1, -1);

    function<ll(int)> dp = [&](int l) {
        if (l >= a.size()) return static_cast<ll>(0);

        if(memo[l] == -1) {
            memo[l] = a[l] + dp(l + 1);
            memo[l] = max(memo[l], dp(l + 1));
        }

        return memo[l];
    };


    if(sum > dp(1)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << "\n";
}

int main()
{
    int t, n;

    vector<ll> a;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while(t--) {
        cin >> n;

        a.resize(n);

        for(auto i = 0; i < n; ++i) cin >> a[i];

        solve(a);
    }

    return 0;
}

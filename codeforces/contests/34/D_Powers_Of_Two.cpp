#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(ll n, ll k)
{
    ll tmp;
    vector<ll> pow_two;

    map<pair<ll, ll>, bool> memo;
    vector<ll> res;

    tmp = 0;
    while ((1 << tmp) <= n) {
        pow_two.push_back(1 << tmp);
        ++tmp;
    }

    function<bool(ll, ll)> dp = [&](ll amount, ll k) {
        if (amount == 0) {
            if (k == 0)
                return true;
            else
                return false;
        }
        if (k <= 0)
            return false;

        if (!memo[{amount, k}]) {
            for (auto p : pow_two) {
                if (p > amount) {
                    break;
                }

                if (dp(amount - p, k - 1)) {
                    res.push_back(p);
                    return true;
                }
            }
            memo[{amount, k}] = true;
        }

        return false;
    };

    if (dp(n, k)) {
        cout << "YES\n";
        for (auto r : res) {
            cout << r << " ";
        }
    } else {
        cout << "NO";
    }
    cout << "\n";
}

int main()
{
    ll n, k;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    solve(n, k);

    return 0;
}

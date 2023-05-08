#include <bits/stdc++.h>

using namespace std;

/**
 * Coprime
 *
 * https://codeforces.com/gym/442062/problem/F
 *
 * Time - O(n^2) # since constrint is 1 - 1000 atmost 10^6
 * Space - O(n)
 */

int gcd(int a, int b)
{
    if (a == 0)
        return b;

    return gcd(b % a, a);
}

int main()
{
    int t, n, input;
    int res;

    vector<int> a;
    map<int, int> idx;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;

    for (auto _ = 0; _ < t; ++_) {
        cin >> n;
        idx.clear();

        for (auto i = 0; i < n; ++i) {
            cin >> input;
            idx[input] = i;
        }

        n = idx.size();
        a.clear();
        a.reserve(n);
        for (auto &[k, _] : idx) a.push_back(k);

        res = -1;
        for (auto i = 0; i < n; ++i) {
            for (auto j = i; j < n; ++j) {
                if (gcd(a[i], a[j]) == 1) {
                    res = max(res, idx[a[i]] + idx[a[j]] + 2);
                }
            }
        }

        cout << res << "\n";
    }

    return 0;
}

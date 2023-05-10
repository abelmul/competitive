#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;

    int res, tmp, s;
    vector<int> factors;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> n;

        factors.clear();
        res = 0;

        for (auto i = 0; i < n; ++i) {
            cin >> tmp;

            while (tmp && tmp % 2 == 0) {
                tmp /= 2;
                ++res;
            }

            s = 0;
            tmp = i + 1;
            while (tmp && tmp % 2 == 0) {
                tmp /= 2;
                ++s;
            }

            if (s) {
                factors.push_back(s);
            }
        }

        if (res >= n) {
            res = 0;
        } else {
            sort(factors.rbegin(), factors.rend());

            n = n - res;
            res = 0;
            for (auto f : factors) {
                if (n <= 0)
                    break;

                n -= f;
                ++res;
            }

            if (n > 0) {
                res = -1;
            }
        }

        cout << res << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;

    int sum, res;
    vector<int> a;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> n;

        a.resize(n);
        res = sum = 0;

        for (auto i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        if (sum % 2) {
            bool found = false;

            while (!found) {
                ++res;
                for (auto n : a) {
                    // check if the last bit changes when we divide it by 2^res
                    found = (n & 1) ^ ((n >> res) & 1);
                    if (found)
                        break;
                }
            }
        }

        cout << res << "\n";
    }

    return 0;
}

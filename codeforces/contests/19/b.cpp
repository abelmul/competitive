#include <bits/stdc++.h>

using namespace std;

/**
 * Odd Divisor
 * https://codeforces.com/gym/442062/problem/B
 * 
 * Time - O(log(n))
 * Space - O(n)
*/

int main()
{
    long long t, n;
    string res;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    for (auto _ = 0; _ < t; ++_) {
        cin >> n;

        res = "YES";

        if (n % 2 == 0) {
            res = "NO";

            while (n) {
                if (n % 2) {
                    if (n != 1) {
                        res = "YES";
                    }
                    break;
                }

                n /= 2;
            }
        }

        cout << res << "\n";
    }

    return 0;
}

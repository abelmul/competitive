#include <bits/stdc++.h>

using namespace std;

/**
 * Basketball Together
 * https://codeforces.com/gym/437545/problem/C
 *
 * Time - O(nlog(n))
 * Space - O(1)
 */

int main()
{
    int N, D;
    vector<int> P;

    int res = 0;
    int needed, l, r;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> D;

    P.resize(N);

    for (auto i = 0; i < N; ++i) cin >> P[i];

    sort(P.begin(), P.end(), greater<>());

    l = 0;
    r = N - 1;

    while (l <= r) {
        needed = (D / P[l]) + ((D % P[l]) != 0);

        if (P[l] * needed <= D)
            ++needed;

        if (needed > (r - l + 1)) {
            break;
        }

        ++l;
        r -= needed - 1;

        ++res;
    }

    cout << res << "\n";

    return 0;
}

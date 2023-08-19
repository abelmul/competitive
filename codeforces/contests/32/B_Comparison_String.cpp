#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    string s;

    int res, cur;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while(t--) {
        cin >> n;
        cin >> s;

        res = cur = 1;

        for(auto i = 1; i < n; ++i) {
            cur = s[i] != s[i-1] ? 1 : cur + 1;
            res = max(res, cur);
        }

        cout << res + 1 << "\n";

    }

    return 0;
}
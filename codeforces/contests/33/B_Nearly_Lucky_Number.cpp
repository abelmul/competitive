#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int luckies = 0;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;

    for (auto c : s) {
        if (c == '4' || c == '7') {
            ++luckies;
        }
    }

    cout << (luckies == 4 || luckies == 7 ? "YES" : "NO") << "\n";

    return 0;
}

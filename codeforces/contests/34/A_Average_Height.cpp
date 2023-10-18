#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;

    int tmp;
    vector<int> evens, odds;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while(t--) {
        cin >> n;

        evens.clear();
        odds.clear();
        for(auto i = 0; i < n; ++i) {
            cin >> tmp;
            if (tmp % 2) odds.push_back(tmp);
            else evens.push_back(tmp);
        }

        for(auto o : odds) cout << o << " ";
        for(auto e : evens) cout << e << " ";
        cout << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;

    vector<pair<long long, long long>> ab;
    unordered_set<long long> broken;
    unordered_map<long long, long long> counter;

    long long res, turned_on;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;

        broken.clear();
        counter.clear();
        ab.resize(n);
        turned_on = 0;

        res = 0;

        for (auto i = 0; i < n; ++i) cin >> ab[i].first >> ab[i].second;

        sort(ab.begin(), ab.end(), [](auto a, auto b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }

            return a.first < b.first;
        });

        for (auto i = 0; i < n; ++i) {
            if (broken.find(ab[i].first) == broken.end()) {
                res += ab[i].second;
                ++counter[ab[i].first];

                ++turned_on;

                if (counter.find(turned_on) != counter.end()) {
                    auto tmp = turned_on;

                    broken.insert(tmp);
                    turned_on -= counter[tmp];
                    counter.erase(tmp);
                }
            }
        }

        cout << res << "\n";
    }

    return 0;
}

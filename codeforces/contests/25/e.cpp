#include <bits/stdc++.h>

using namespace std;

/**
 * Heap Operations
 * https://codeforces.com/gym/447850/problem/E
 *
 * Time - O(log(m))
 * Space - O(n)
 */

int main()
{
    int n;

    string s;
    int d;
    priority_queue<long, vector<long>, greater<long>> pq;

    vector<string> res;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    while (n--) {
        cin >> s;

        if (s == "insert") {
            cin >> d;
            pq.push(d);

            res.push_back(s + " " + to_string(d));
        } else if (s == "removeMin") {
            if (pq.empty()) {
                res.push_back("insert 0");
            } else {
                pq.pop();
            }
            res.push_back(s);
        } else if (s == "getMin") {
            cin >> d;
            while (!pq.empty() && d > pq.top()) {
                res.push_back("removeMin");
                pq.pop();
            }

            if (pq.empty() || d != pq.top()) {
                pq.push(d);
                res.push_back("insert " + to_string(d));
            }

            res.push_back(s + " " + to_string(d));
        }
    }

    cout << res.size() << "\n";
    for (auto r : res) cout << r << "\n";

    return 0;
}

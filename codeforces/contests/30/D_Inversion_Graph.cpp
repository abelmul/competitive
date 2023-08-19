#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;

    int p, c;
    vector<int> st;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> n;

        st.clear();

        for (auto _ = 0; _ < n; ++_) {
            cin >> c;
            if (st.empty() || c > st.back()) {
                st.push_back(c);
            } else {
                p = st.back();
                while (!st.empty() && st.back() > c) {
                    st.pop_back();
                }
                st.push_back(p);
            }
        }

        cout << st.size() << "\n";
    }

    return 0;
}

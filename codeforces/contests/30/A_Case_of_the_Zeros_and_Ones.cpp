#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;

    stack<char> st;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> s;

    for(auto i = 0; i < n; ++i) {
        if (st.empty() || st.top() == s[i]) {
            st.push(s[i]);
        } else if (!st.empty()) {
            st.pop();
        }
    }

    cout << st.size() << "\n";

    return 0;
}

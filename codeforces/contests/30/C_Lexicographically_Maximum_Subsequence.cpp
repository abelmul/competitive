#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    vector<char> max_st;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;

    for (auto c : s) {
        while (!max_st.empty() && max_st.back() < c) {
            max_st.pop_back();
        }
        max_st.push_back(c);
    }

    for (auto c : max_st) {
        cout << c;
    }

    cout << "\n";

    return 0;
}

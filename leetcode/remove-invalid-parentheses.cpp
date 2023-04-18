#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool isValid(const string& s, set<int> removed)
    {
        stack<char> st;
        char v;

        auto length = s.size();

        for (auto i = 0; i < length; ++i) {
            if (removed.find(i) == removed.end()) {
                v = s[i];

                if (v == '(') {
                    st.push(v);
                } else if (v == ')') {
                    if (st.empty())
                        return false;
                    st.pop();
                }
            }
        }

        return st.empty();
    }

    vector<string> removeInvalidParentheses(string s)
    {
        auto length = s.size();

        set<int> removed;

        vector<string> res;
        int min_removed = INT_MAX;

        function<void(int, set<int>&, int)> backtrack = [&](int l, set<int>& removed, int r) {
            if (r > min_removed) {
                return;
            }

            if (isValid(s, removed)) {
                if (min_removed > r) {
                    res.clear();
                }

                string tmp;

                for (auto i = 0; i < length; ++i) {
                    if (removed.find(i) == removed.end()) {
                        tmp.push_back(s[i]);
                    }
                }

                min_removed = r;
                res.push_back(tmp);
            }

            for (auto i = l; i < length; ++i) {
                if (i <= l || s[i - 1] != s[i]) {
                    removed.insert(i);
                    backtrack(i + 1, removed, r + 1);
                    removed.erase(i);
                }
            }
        };

        backtrack(0, removed, 0);

        return res;
    }
};

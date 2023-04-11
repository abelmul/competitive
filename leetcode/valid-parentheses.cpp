#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool isValid(string s)
    {
        stack<char> st;
        set<char> opening = {'(', '[', '{'};
        unordered_map<char, char> ending = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        for (auto c : s) {
            if (opening.find(c) != opening.end()) {
                st.push(c);
            } else {
                if (st.empty() || st.top() != ending[c])
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

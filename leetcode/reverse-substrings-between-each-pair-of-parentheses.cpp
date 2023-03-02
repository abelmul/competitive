#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    char topandpop(vector<char>& t)
    {
        auto s = t.back();
        t.pop_back();
        return s;
    }

    string reverseParentheses(string str)
    {
        vector<char> reverser;

        for (char s : str) {
            if (s == ')') {
                char i = topandpop(reverser);
                string reversed = "";
                while (i != '(') {
                    reversed.push_back(i);
                    i = topandpop(reverser);
                }

                for (char r : reversed) {
                    reverser.push_back(r);
                }
            } else {
                reverser.push_back(s);
            }
        }

        return string(reverser.begin(), reverser.end());
    }
};

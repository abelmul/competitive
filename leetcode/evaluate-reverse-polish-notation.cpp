#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    std::string topandpop(vector<string>& t)
    {
        std::string s = t.back();
        t.pop_back();
        return s;
    }
    int evalRPN(vector<string>& tokens)
    {
        vector<string> t;

        for (string s : tokens) {
            string one, two;
            if (s == "+") {
                one = topandpop(t);
                two = topandpop(t);
                t.push_back(to_string(stol(two) + stol(one)));
            } else if (s == "-") {
                one = topandpop(t);
                two = topandpop(t);
                t.push_back(to_string(stol(two) - stol(one)));
            } else if (s == "*") {
                one = topandpop(t);
                two = topandpop(t);
                t.push_back(to_string(stol(two) * stol(one)));
            } else if (s == "/") {
                one = topandpop(t);
                two = topandpop(t);
                t.push_back(to_string(stol(two) / stol(one)));
            } else {
                t.push_back(s);
            }
        }

        return stoi(t.back());
    }
};

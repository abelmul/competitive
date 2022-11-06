#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    std::string topandpop(stack<string>& t) {
      std::string s = t.top();
      t.pop();
      return s;
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> t;
        
        for(string s: tokens) {
            string one, two;
            if (s == "+") {
              one = topandpop(t);
              two = topandpop(t);
              t.push(to_string(stol(two) + stol(one)));
            }
            else if (s == "-") {
              one = topandpop(t);
              two = topandpop(t);
              t.push(to_string(stol(two) - stol(one)));
            }
            else if (s == "*") {
              one = topandpop(t);
              two = topandpop(t);
              t.push(to_string(stol(two) * stol(one)));
            }
            else if (s == "/") {
              one = topandpop(t);
              two = topandpop(t);
              t.push(to_string(stol(two) / stol(one)));
            } else {
                t.push(s);
            }
        }
        
        return stoi(t.top());
    }
};

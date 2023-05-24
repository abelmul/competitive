#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    string toLowerCase(string s)
    {
        auto size = s.size();

        for (auto i = 0; i < size; ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = 'a' + (s[i] - 'A');
            }
        }

        return s;
    }
};

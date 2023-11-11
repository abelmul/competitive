#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int numDecodings(string s)
    {
        auto n = s.size();

        int next = 0, next_next = 0;
        int current = 1;

        for (int i = n; i >= 0; --i) {
            next_next = next;
            next = current;
            if (s[i] == '0') {
                current = 0;
            } else {
                current = next;

                if (i + 1 < n && (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26) {
                    current += next_next;
                }
            }
        }

        return current;
    }
};

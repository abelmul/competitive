#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int numDecodings(string s)
    {
        int size = s.size();

        vector<int> memo(size, -1);

        auto toNum = [](char x, char y) { return (x - '0') * 10 + (y - '0'); };

        function<int(int)> dp = [&](int i) {
            if (i >= size)
                return 1;
            if (s[i] == '0')
                return 0;

            if (memo[i] == -1) {
                memo[i] = dp(i + 1);

                if (i + 1 < size && toNum(s[i], s[i + 1]) <= 26) {
                    memo[i] += dp(i + 2);
                }
            }

            return memo[i];
        };

        return dp(0);
    }
};

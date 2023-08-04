#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int integerReplacement(int n)
    {
        unordered_map<long long, int> memo;

        function<int(long long)> dp = [&](long long i) {
            if (i == 1)
                return 0;

            if (memo.find(i) == memo.end()) {
                memo[i] = 1;
                if (i % 2) {
                    memo[i] += min(dp(i + 1), dp(i - 1));
                } else {
                    memo[i] += dp(i / 2);
                }
            }

            return memo[i];
        };

        return dp(n);
    }
};

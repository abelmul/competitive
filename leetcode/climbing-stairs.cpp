#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int climbStairs(int n)
    {
        unordered_map<int, int> memo;

        function<int(int)> solve = [&](int n) {
            if (n <= 0) {
                return int(n == 0);
            }

            if (memo.find(n) == memo.end()) {
                memo[n] = solve(n - 1) + solve(n - 2);
            }

            return memo[n];
        };

        return solve(n);
    }
};

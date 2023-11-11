#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int recurse(int n, vector<int>& memo)
    {
        if (n <= 1)
            return n;
        if (memo[n] != -1)
            return memo[n];

        memo[n] = recurse(n - 1, memo) + recurse(n - 2, memo);

        return memo[n];
    }

    int fib(int n)
    {
        vector<int> memo(n + 2, -1);

        return recurse(n, memo);
    }
};

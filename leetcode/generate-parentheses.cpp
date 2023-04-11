#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;

        function<void(string, int, int)> backtrack = [&](string s, int left,
                                                         int right) {
            if (left == 0 && right == 0) {
                res.push_back(s);
            }

            if (left > 0) {
                backtrack(s + "(", left - 1, right);
            }

            if (right > 0 && right > left) {
                backtrack(s + ")", left, right - 1);
            }
        };

        backtrack("", n, n);

        return res;
    }
};

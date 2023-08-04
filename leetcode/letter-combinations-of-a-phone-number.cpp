#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<string> letterCombinations(string digits)
    {
        const string map[] = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
        };
        auto size = digits.size();

        vector<string> res;
        string cur;

        cur.reserve(size);

        function<void(int, string)> backtrack = [&](int l, string cur) {
            if (l >= size) {
                if (cur.size() > 0) {
                    res.push_back(cur);
                }
                return;
            }

            for (auto c : map[digits[l] - '0']) {
                cur.push_back(c);
                backtrack(l + 1, cur);
                cur.pop_back();
            }
        };

        backtrack(0, cur);

        return res;
    }
};

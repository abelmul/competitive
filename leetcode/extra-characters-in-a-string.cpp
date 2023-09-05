#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int minExtraChar(string s, vector<string>& dictionary)
    {
        int size = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        vector<int> memo(size, -1);

        function<int(int)> dp = [&](int i) {
            if (i >= size) {
                return 0;
            }

            if (memo[i] == -1) {
                memo[i] = 1 + dp(i + 1);

                for (auto j = i; j < size; ++j) {
                    if (dict.find(s.substr(i, j - i + 1)) != dict.end()) {
                        memo[i] = min(memo[i], dp(j + 1));
                    }
                }
            }

            return memo[i];
        };

        return dp(0);
    }
};

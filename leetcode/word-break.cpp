#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        auto size = s.size();

        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> memo(size, -1);

        function<int(int)> dp = [&](int l) {
            if (l >= size)
                return 1;

            string tmp;
            // tmp.reserve(size - l);

            if (memo[l] == -1) {
                memo[l] = 0;
                for (auto i = l; i < size; ++i) {
                    tmp.push_back(s[i]);
                    if (dict.find(tmp) != dict.end()) {
                        auto r = dp(i + 1);
                        if (r > 0) {
                            memo[l] = 1 + 1;
                            break;
                        }
                    }
                };
            }

            return memo[l];
        };

        return dp(0) > 0;
    }
};

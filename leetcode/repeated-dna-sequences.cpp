#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        auto size = s.size();
        vector<string> res;

        if (size >= 10) {
            unordered_map<string, int> counter;

            counter[s.substr(0, 10)] = 1;

            for (auto i = 1; i < size; ++i) {
                auto substr = s.substr(i, 10);

                if (substr.size() < 10)
                    break;

                ++counter[substr];
                if (counter[substr] == 2) {
                    res.push_back(substr);
                }
            }
        }

        return res;
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    string mergeAlternately(string word1, string word2)
    {
        auto len1 = word1.size();
        auto len2 = word2.size();

        string res;
        res.reserve(len1 + len2);

        for (auto i = 0; i < min(len1, len2); ++i) {
            res.push_back(word1[i]);
            res.push_back(word2[i]);
        }

        for (auto i = min(len1, len2); i < len1; ++i) {
            res.push_back(word1[i]);
        }

        for (auto i = min(len1, len2); i < len2; ++i) {
            res.push_back(word2[i]);
        }

        return res;
    }
};

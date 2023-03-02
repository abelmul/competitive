#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int is_anagram(string a, const vector<int>& phash)
    {
        vector<int> hash(26, 0);
        auto window = a.size();

        for (int i = 0; i < window; ++i) hash[a[i] - 'a'] += 1;

        return phash == hash;
    }

    vector<int> findAnagrams(string s, string p)
    {
        auto size = s.size();
        int window = p.size();
        vector<int> phash(26, 0);
        vector<int> answer;

        if (size < window)
            return answer;

        for (int i = 0; i < window; ++i) phash[p[i] - 'a'] += 1;

        if (is_anagram(s.substr(0, window), phash))
            answer.push_back(0);

        for (int i = window + 1; i < size + 1; ++i) {
            if (is_anagram(s.substr(i - window, window), phash))
                answer.push_back(i - window);
        }

        return answer;
    }
};

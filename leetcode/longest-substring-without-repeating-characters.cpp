#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int lengthOfLongestSubstring(string s)
    {
        auto size = s.size();
        int current_max = 0;

        for (int i = 0; i < size; ++i) {
            int window_max = 1;
            unordered_map<char, bool> map;

            map[s[i]] = true;

            for (int j = i + 1; j < size; ++j) {
                if (map.find(s[j]) != map.end())
                    break;

                map[s[j]] = true;
                ++window_max;
            }
            current_max = max(window_max, current_max);
        }

        return current_max;
    }
};

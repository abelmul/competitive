#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool buddyStrings(string s, string goal)
    {
        vector<int> char_index;
        unordered_map<char, int> counter;
        auto size = s.size();

        if (s == goal) {
            // are there duplicate letters
            for (auto i = 0; i < size; ++i) {
                ++counter[s[i]];
                if (counter[s[i]] > 1) {
                    return true;
                }
            }
        } else if (s.size() == goal.size()) {
            for (auto i = 0; i < size; ++i) {
                if (s[i] != goal[i]) {
                    for (auto j = i; j < size; ++j) {
                        if (s[j] == goal[i]) {
                            char_index.push_back(j);
                        }
                    }

                    for (auto ind : char_index) {
                        swap(s[i], s[ind]);
                        if (s == goal) {
                            return true;
                        }
                        swap(s[i], s[ind]);
                    }
                    break;
                }
            }
        }

        return false;
    }
};

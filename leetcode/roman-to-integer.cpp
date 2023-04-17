#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int romanToInt(string s)
    {
        int length = s.size();
        int res = 0;
        char prev = s[length - 1];

        unordered_map<char, int> hashmap = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                            {'C', 100}, {'D', 500}, {'M', 1000}};

        for (auto i = length - 1; i >= 0; --i) {
            if (hashmap[s[i]] < hashmap[prev]) {
                res -= hashmap[s[i]];
            } else {
                res += hashmap[s[i]];
            }
            prev = s[i];
        }

        return res;
    }
};

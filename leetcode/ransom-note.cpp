#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> count;

        for(auto c : magazine) {
            ++count[c];
        }

        for(auto c : ransomNote) {
            --count[c];

            if (count[c] < 0)
                return false;
        }

        return true;
    }
};

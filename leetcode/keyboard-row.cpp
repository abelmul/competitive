#include <bits/stdc++.h>

using namespace std;

class Solution
{
 private:
    unordered_set<char> first_row = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    unordered_set<char> second_row = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    unordered_set<char> third_row = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

 public:
    bool isInOneRow(string word)
    {
        unordered_set<char>* s;

        if (first_row.find(tolower(word[0])) != first_row.end()) {
            s = &first_row;
        } else if (second_row.find(tolower(word[0])) != second_row.end()) {
            s = &second_row;
        } else {
            s = &third_row;
        }

        for (auto i = 1; i < word.size(); ++i) {
            if (s->find(tolower(word[i])) == s->end())
                return false;
        }

        return true;
    }

    vector<string> findWords(vector<string>& words)
    {
        vector<string> res;
        for (auto w : words) {
            if (isInOneRow(w)) {
                res.push_back(w);
            }
        }

        return res;
    }
};

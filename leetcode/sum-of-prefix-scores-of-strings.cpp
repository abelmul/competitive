#include <bits/stdc++.h>

using namespace std;

class Solution
{
 private:
    struct TrieNode {
        TrieNode* children[26];
        int count;

        TrieNode() : count(0) { fill(begin(children), end(children), nullptr); }

        void insert(const string& s)
        {
            auto ptr = this;
            for (auto c : s) {
                if (ptr->children[c - 'a'] == nullptr) {
                    ptr->children[c - 'a'] = new TrieNode();
                }
                ptr = ptr->children[c - 'a'];
                ++ptr->count;
            }
        };

        int prefixCount(const string& s)
        {
            int res = 0;
            auto ptr = this;
            for (auto c : s) {
                res += ptr->children[c - 'a']->count;
                ptr = ptr->children[c - 'a'];
            }
            return res;
        }
    };

 public:
    vector<int> sumPrefixScores(vector<string>& words)
    {
        auto n = words.size();

        TrieNode root = TrieNode();
        vector<int> res(n);

        for (auto i = 0; i < n; ++i) {
            root.insert(words[i]);
        }

        for (auto i = 0; i < n; ++i) {
            res[i] = root.prefixCount(words[i]);
        }

        return res;
    }
};

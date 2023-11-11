#include <bits/stdc++.h>

using namespace std;

class Solution
{
 private:
    struct TrieNode {
        TrieNode* children[26];
        int markWord;

        TrieNode() : markWord(0) { fill(begin(children), end(children), nullptr); }

        void insert(const string& s)
        {
            auto ptr = this;
            for (auto c : s) {
                if (ptr->children[c - 'a'] == nullptr) {
                    ptr->children[c - 'a'] = new TrieNode();
                }
                ptr = ptr->children[c - 'a'];
            }
            ++ptr->markWord;
        };
    };

    int dfs(TrieNode* root, const vector<int>* char_idx, int last_idx)
    {
        int res = 0;

        for (auto i = 0; i < 26; ++i) {
            if (root->children[i] != nullptr) {
                auto u = upper_bound(char_idx[i].begin(), char_idx[i].end(), last_idx);
                if (u != char_idx[i].end()) {
                    res += dfs(root->children[i], char_idx, char_idx[i][u - char_idx[i].begin()]);
                }
            }
        }

        return res + root->markWord;
    }

 public:
    int numMatchingSubseq(string s, vector<string>& words)
    {
        int res = 0;

        vector<int> char_idx[26];
        TrieNode root = TrieNode();

        for (auto w : words) {
            root.insert(w);
        }

        for (auto i = 0; i < s.size(); ++i) {
            char_idx[s[i] - 'a'].push_back(i);
        }

        return dfs(&root, char_idx, -1);
    }
};

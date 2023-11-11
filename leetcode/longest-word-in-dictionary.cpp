#include <bits/stdc++.h>

using namespace std;

class Solution
{
 private:
    struct TrieNode {
        TrieNode* children[26];
        bool markWord;

        TrieNode() : markWord(false) { fill(begin(children), end(children), nullptr); }

        void insert(const string& s)
        {
            auto ptr = this;
            for (auto c : s) {
                if (ptr->children[c - 'a'] == nullptr) {
                    ptr->children[c - 'a'] = new TrieNode();
                }
                ptr = ptr->children[c - 'a'];
            }
            ptr->markWord = true;
        };
    };

    string dfs(TrieNode* root)
    {
        string res = "";

        for (auto i = 0; i < 26; ++i) {
            if (root->children[i] != nullptr && root->children[i]->markWord) {
                string s = "";
                s.push_back(i + 'a');
                s += dfs(root->children[i]);

                if (s.size() > res.size()) {
                    res = s;
                }
            }
        }

        return res;
    }

 public:
    string longestWord(vector<string>& words)
    {
        TrieNode root = TrieNode();

        for (auto w : words) {
            root.insert(w);
        }

        return dfs(&root);
    }
};

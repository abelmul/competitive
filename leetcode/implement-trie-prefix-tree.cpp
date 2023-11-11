#include <bits/stdc++.h>

using namespace std;

class Trie
{
 private:
    struct TrieNode {
        TrieNode* children[26];
        bool markWord;
        TrieNode(bool markWord) : markWord(markWord)
        {
            fill(begin(children), end(children), nullptr);
        }
    };

 public:
    TrieNode* root;

    Trie() { root = new TrieNode(false); }

    void insert(string word)
    {
        TrieNode* ptr = root;
        auto n = word.size();

        for (auto i = 0; i < n; ++i) {
            if (ptr->children[word[i] - 'a'] == nullptr) {
                ptr->children[word[i] - 'a'] = new TrieNode(false);
            }
            ptr = ptr->children[word[i] - 'a'];
        }

        ptr->markWord = true;
    }

    bool search(string word)
    {
        TrieNode* ptr = root;

        for (auto c : word) {
            if (ptr->children[c - 'a'] == nullptr)
                return false;
            ptr = ptr->children[c - 'a'];
        }

        return ptr->markWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode* ptr = root;

        for (auto c : prefix) {
            if (ptr->children[c - 'a'] == nullptr)
                return false;
            ptr = ptr->children[c - 'a'];
        }

        return true;
    }
};

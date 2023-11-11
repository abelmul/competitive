#include <bits/stdc++.h>

using namespace std;

class WordDictionary
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

    bool searchHelper(TrieNode* ptr, const string& word, int i)
    {
        auto n = word.size();

        for (; i < n; ++i) {
            if (word[i] == '.') {
                for (auto t : ptr->children) {
                    if (t != nullptr && searchHelper(t, word, i + 1)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (ptr->children[word[i] - 'a'] == nullptr)
                    return false;

                ptr = ptr->children[word[i] - 'a'];
            }
        }

        return ptr->markWord;
    }

 public:
    TrieNode* root;
    WordDictionary() { root = new TrieNode(false); }

    void addWord(string word)
    {
        auto ptr = root;
        for (auto c : word) {
            if (ptr->children[c - 'a'] == nullptr) {
                ptr->children[c - 'a'] = new TrieNode(false);
            }
            ptr = ptr->children[c - 'a'];
        }
        ptr->markWord = true;
    }

    bool search(string word) { return searchHelper(root, word, 0); }
};

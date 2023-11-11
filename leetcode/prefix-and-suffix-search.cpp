#include <bits/stdc++.h>

using namespace std;

class WordFilter
{
 private:
    struct TrieNode {
        TrieNode* children[26];
        vector<int> pre_idxs;
        vector<int> suf_idxs;

        TrieNode() { fill(begin(children), end(children), nullptr); }

        ~TrieNode()
        {
            for (auto c : children) {
                if (c != nullptr)
                    delete c;
            }
        }

        void insert(const string& s, int idx)
        {
            auto n = s.size();

            // store prefix
            auto ptr = this;
            for (auto i = 0; i < n; ++i) {
                if (ptr->children[s[i] - 'a'] == nullptr) {
                    ptr->children[s[i] - 'a'] = new TrieNode();
                }
                ptr = ptr->children[s[i] - 'a'];
                ptr->pre_idxs.push_back(idx);
            }

            // store suffix
            ptr = this;
            for (int i = n - 1; i >= 0; --i) {
                if (ptr->children[s[i] - 'a'] == nullptr) {
                    ptr->children[s[i] - 'a'] = new TrieNode();
                }
                ptr = ptr->children[s[i] - 'a'];
                ptr->suf_idxs.push_back(idx);
            }
        }
    };
    TrieNode* root;

 public:
    WordFilter(vector<string> words)
    {
        root = new TrieNode();
        auto n = words.size();

        for (auto i = 0; i < n; ++i) {
            root->insert(words[i], i);
        }
    }

    ~WordFilter() { delete root; }

    int f(string pref, string suff)
    {
        int res = -1;

        auto ptr = root;
        vector<int>* pre_idxs;

        for (auto c : pref) {
            if (ptr->children[c - 'a'] == nullptr) {
                ptr = nullptr;
                break;
            }
            ptr = ptr->children[c - 'a'];
        }

        if (ptr != nullptr) {
            pre_idxs = &ptr->pre_idxs;

            ptr = root;
            for (int i = suff.size() - 1; i >= 0; --i) {
                if (ptr->children[suff[i] - 'a'] == nullptr) {
                    ptr = nullptr;
                    break;
                }
                ptr = ptr->children[suff[i] - 'a'];
            }

            if (ptr != nullptr) {
                auto pre_end = pre_idxs->rbegin(), pre_begin = pre_idxs->rend();
                auto suf_end = ptr->suf_idxs.rbegin(), suf_begin = ptr->suf_idxs.rend();

                while (pre_end != pre_begin && suf_end != suf_begin) {
                    if (*pre_end > *suf_end) {
                        ++pre_end;
                    } else if (*pre_end < *suf_end) {
                        ++suf_end;
                    } else {
                        res = *pre_end;
                        break;
                    }
                }
            }
        }

        return res;
    }
};

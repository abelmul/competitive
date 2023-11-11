#include <bits/stdc++.h>

using namespace std;

class MapSum
{
    struct TrieNode {
        TrieNode* children[26];
        int val;

        TrieNode(int val = 0) : val(val) { fill(begin(children), end(children), nullptr); }
    };
    TrieNode* root;

 public:
    MapSum() { root = new TrieNode(); }

    void insert(string key, int val)
    {
        auto ptr = root;

        for (auto c : key) {
            if (ptr->children[c - 'a'] == nullptr) {
                ptr->children[c - 'a'] = new TrieNode();
            }
            ptr = ptr->children[c - 'a'];
        }
        ptr->val = val;
    }

    int sum(string prefix)
    {
        auto ptr = root;

        for (auto c : prefix) {
            if (ptr->children[c - 'a'] == nullptr)
                return 0;

            ptr = ptr->children[c - 'a'];
        }

        function<int(TrieNode*)> dfs = [&](TrieNode* node) {
            int res = 0;

            if (node != nullptr) {
                res += node->val;

                for (auto c : node->children) {
                    res += dfs(c);
                }
            }

            return res;
        };

        return dfs(ptr);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

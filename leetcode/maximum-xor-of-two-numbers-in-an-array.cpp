#include <bits/stdc++.h>

using namespace std;

class Solution
{
 private:
    struct TrieNode {
        TrieNode* children[2];

        TrieNode() { children[0] = children[1] = nullptr; }

        void insert(int x)
        {
            char b;
            auto ptr = this;

            for (auto i = 31; i >= 0; --i) {
                b = (x >> i) & 1;

                if (ptr->children[b] == nullptr) {
                    ptr->children[b] = new TrieNode();
                }
                ptr = ptr->children[b];
            }
        };

        int searchMaxXor(int x)
        {
            char b, o_b;
            auto ptr = this;

            int res = 0;

            for (auto i = 31; i >= 0; --i) {
                b = (x >> i) & 1;
                o_b = !b;

                res <<= 1;

                if (ptr->children[o_b] != nullptr) {
                    res |= o_b;
                    ptr = ptr->children[o_b];
                } else if (ptr->children[b] != nullptr) {
                    res |= b;
                    ptr = ptr->children[b];
                }
            }

            return x ^ res;
        }
    };

 public:
    int findMaximumXOR(vector<int>& nums)
    {
        int res = 0;
        TrieNode* root = new TrieNode();

        for (auto n : nums) {
            root->insert(n);
        }

        for (auto n : nums) {
            res = max(res, root->searchMaxXor(n));
        }

        return res;
    }
};

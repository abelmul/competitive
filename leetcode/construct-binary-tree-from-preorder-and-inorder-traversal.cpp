#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
 public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int ps = 0;
        auto i_size = inorder.size(), p_size = preorder.size();

        unordered_map<int, int> imap;

        for (auto i = 0; i < i_size; ++i) {
            imap[inorder[i]] = i;
        }

        function<TreeNode *(int, int, int &)> solve = [&](int is, int ie, int &ps) {
            // divide and conquer
            if (is >= ie || ps >= p_size) {
                return (TreeNode *)nullptr;
            }

            TreeNode *node = new TreeNode(preorder[ps]);

            // remove root
            ++ps;

            if (is + 1 < ie) {
                // get pos of root in inorder
                int i_root = imap[preorder[ps - 1]];

                node->left = solve(is, i_root, ps);
                node->right = solve(i_root + 1, ie, ps);
            }

            return node;
        };

        return solve(0, i_size, ps);
    }
};

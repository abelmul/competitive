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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        auto i_size = inorder.size();
        int pe = postorder.size() - 1;

        unordered_map<int, int> imap;

        for (auto i = 0; i < i_size; ++i) {
            imap[inorder[i]] = i;
        }

        function<TreeNode *(int, int, int &)> solve = [&](int is, int ie, int &pe) {
            if (is >= ie) {
                return (TreeNode *)nullptr;
            }
            TreeNode *node = new TreeNode(postorder[pe]);
            int i_root;

            // remove root
            --pe;

            if (is + 1 < ie) {
                // get pos of root in inorder
                i_root = imap[postorder[pe + 1]];

                node->right = solve(i_root + 1, ie, pe);
                node->left = solve(is, i_root, pe);
            }
            return node;
        };

        return solve(0, i_size, pe);
    }
};

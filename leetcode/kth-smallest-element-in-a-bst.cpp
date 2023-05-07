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
    int kthSmallest(TreeNode *root, int k)
    {
        TreeNode *res;

        function<int(TreeNode *, int)> inorder = [&](TreeNode *root, int k) {
            if (!root) {
                return k;
            }

            if (root->left) {
                k = inorder(root->left, k);
            }
            if (k >= 1) {
                res = root;
                --k;
            }

            if (k == 0)
                return 0;

            return inorder(root->right, k);
        };

        inorder(root, k);

        return res->val;
    }
};

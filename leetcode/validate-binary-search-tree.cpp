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
    bool isValidBST(TreeNode *root)
    {
        vector<int> res;
        int length;

        function<void(TreeNode *)> inorder = [&](TreeNode *root) {
            if (!root)
                return;

            inorder(root->left);
            res.push_back(root->val);
            inorder(root->right);
        };

        inorder(root);

        length = res.size();

        for (auto i = 1; i < length; ++i) {
            if (res[i] <= res[i - 1])
                return false;
        }

        return true;
    }
};

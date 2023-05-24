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
    long dfs(TreeNode *node, long prev)
    {
        if (!node) {
            return prev;
        }

        prev = prev * 10 + node->val;

        if (!node->right && !node->left) {
            return prev;
        }

        int res = 0;

        if (node->left) {
            res += dfs(node->left, prev);
        }

        if (node->right) {
            res += dfs(node->right, prev);
        }

        return res;
    }

    int sumNumbers(TreeNode *root) { return dfs(root, 0); }
};

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
    int rob(TreeNode *root)
    {
        unordered_map<TreeNode *, int> memo;

        function<int(TreeNode *)> dp = [&](TreeNode *node) {
            if (node == nullptr) {
                return 0;
            }

            if (memo.find(node) == memo.end()) {
                auto inc = node->val;

                if (node->left) {
                    inc += dp(node->left->left) + dp(node->left->right);
                }
                if (node->right) {
                    inc += dp(node->right->left) + dp(node->right->right);
                }

                memo[node] = max(inc, dp(node->left) + dp(node->right));
            }

            return memo[node];
        };

        return dp(root);
    }
};

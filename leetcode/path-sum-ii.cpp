#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};

class Solution
{
 public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> res;
        vector<int> cur;

        function<void(TreeNode *, vector<int> &)> backtrack =
            [&](TreeNode *node, vector<int> cur) {
                if (!node || (!node->left && !node->right)) {
                    // leaf node
                    if (accumulate(cur.begin(), cur.end(), 0) == targetSum) {
                        res.push_back(cur);
                    }
                    return;
                }

                // leave right
                if (node->left) {
                    cur.push_back(node->left->val);
                    backtrack(node->left, cur);
                    cur.pop_back();
                }

                // leave left
                if (node->right) {
                    cur.push_back(node->right->val);
                    backtrack(node->right, cur);
                    cur.pop_back();
                }
            };

        if (root) {
            cur.push_back(root->val);
            backtrack(root, cur);
        }

        return res;
    }
};

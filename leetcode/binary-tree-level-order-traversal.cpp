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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;

        if (root) {
            TreeNode *node;
            int n;
            deque<pair<TreeNode *, int>> queue;

            queue.push_back({root, 0});

            while (!queue.empty()) {
                tie(node, n) = queue.front();
                queue.pop_front();

                if (res.size() <= n) {
                    res.push_back(vector<int>());
                }

                res[n].push_back(node->val);

                if (node->left)
                    queue.push_back({node->left, n + 1});
                if (node->right)
                    queue.push_back({node->right, n + 1});
            }
        }

        return res;
    }
};

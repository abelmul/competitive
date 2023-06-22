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
    int maxLevelSum(TreeNode *root)
    {
        int max_sum = -100'001, current_sum = -100'001;
        int level = 0, current_level = 0;
        int res = 0;

        TreeNode *node;

        deque<pair<TreeNode *, int>> queue;

        queue.emplace_back(root, 1);

        while (!queue.empty()) {
            tie(node, current_level) = queue.front();
            queue.pop_front();

            if (current_level != level) {
                if (current_sum > max_sum) {
                    max_sum = current_sum;
                    res = level;
                }

                level = current_level;
                current_sum = 0;
            }

            if (node) {
                current_sum += node->val;
                queue.emplace_back(node->left, current_level + 1);
                queue.emplace_back(node->right, current_level + 1);
            }
        }

        return res;
    }
};

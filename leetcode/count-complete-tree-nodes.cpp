#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        auto l = 0, r = 0;
        auto left = root, right = root;

        while (left) {
            ++l;
            left = left->left;
        }
        while (right) {
            ++r;
            right = right->right;
        }

        if (l == r)
            return (1 << l) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

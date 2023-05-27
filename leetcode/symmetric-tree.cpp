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
    bool isSymmetric(TreeNode *root)
    {
        if (root) {
            deque<pair<TreeNode *, int>> queue;
            vector<int> current;
            int level = 0;

            queue.push_back({root, 0});

            while (!queue.empty()) {
                pair<TreeNode *, int> node = queue.front();
                queue.pop_front();

                if (level != node.second) {
                    int l = 0, r = current.size() - 1;
                    bool allIs101 = true;

                    while (l <= r) {
                        if (current[l] != current[r]) {
                            return false;
                        }

                        if (current[l] != -101) {
                            allIs101 = false;
                        }

                        ++l;
                        --r;
                    }

                    if (allIs101)
                        break;

                    level = node.second;
                    current.clear();
                }

                if (node.first) {
                    current.push_back(node.first->val);

                    queue.push_back({node.first->left, node.second + 1});
                    queue.push_back({node.first->right, node.second + 1});
                } else {
                    current.push_back(-101);

                    queue.push_back({nullptr, node.second + 1});
                    queue.push_back({nullptr, node.second + 1});
                }
            }
        }

        return true;
    }
};

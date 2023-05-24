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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> res;
        vector<int> current;

        double average;
        int level = 0;
        pair<TreeNode *, int> t;
        deque<pair<TreeNode *, int>> queue;

        if (root) {
            queue.push_back({root, 0});

            while (!queue.empty()) {
                t = queue.front();
                queue.pop_front();

                if (t.second != level) {
                    average = 0;
                    for (auto n : current) {
                        average += n;
                    }
                    average /= current.size();
                    res.push_back(average);

                    current.clear();
                    level = t.second;
                }

                current.push_back(t.first->val);

                if (t.first->left) {
                    queue.push_back({t.first->left, t.second + 1});
                }

                if (t.first->right) {
                    queue.push_back({t.first->right, t.second + 1});
                }
            }
        }

        average = 0;
        for (auto n : current) {
            average += n;
        }
        average /= current.size();
        res.push_back(average);

        return res;
    }
};

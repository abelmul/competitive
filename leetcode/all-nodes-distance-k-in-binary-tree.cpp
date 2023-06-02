#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
 public:
    void getAdjList(TreeNode* root, TreeNode* parent, unordered_map<int, vector<int>>& adjList)
    {
        if (!root)
            return;

        if (parent) {
            adjList[root->val].push_back(parent->val);
        }
        if (root->left) {
            adjList[root->val].push_back(root->left->val);
            getAdjList(root->left, root, adjList);
        }
        if (root->right) {
            adjList[root->val].push_back(root->right->val);
            getAdjList(root->right, root, adjList);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        if (k == 0) {
            return {target->val};
        }

        unordered_map<int, vector<int>> adjList;
        vector<int> res;

        int i;
        deque<int> queue;
        unordered_map<int, int> prev;

        getAdjList(root, nullptr, adjList);

        queue.push_back(target->val);
        prev[target->val] = 0;

        while (!queue.empty()) {
            i = queue.front();
            queue.pop_front();

            if (prev[i] == k) {
                res.push_back(i);
                continue;
            }

            for (auto j : adjList[i]) {
                if (prev.find(j) == prev.end()) {
                    prev[j] = prev[i] + 1;
                    queue.push_back(j);
                }
            }
        }

        return res;
    }
};

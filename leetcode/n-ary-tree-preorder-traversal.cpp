#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node
{
 public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node*> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
 public:
    vector<int> preorder(Node* root)
    {
        Node* node;
        stack<Node*> nodes;
        vector<int> res;

        if (root) {
            nodes.push(root);
        }

        while (!nodes.empty()) {
            node = nodes.top();
            nodes.pop();

            res.push_back(node->val);

            for (auto child = node->children.rbegin(); child != node->children.rend(); ++child)
                nodes.push(*child);
        }

        return res;
    }
};

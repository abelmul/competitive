#include <bits/stdc++.h>

// Definition for a Node.
class Node
{
 public:
    int val;
    std::vector<Node*> neighbors;
    Node()
    {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
 public:
    Node* cloneGraph(Node* node)
    {
        Node* clone = nullptr;

        if (node != nullptr) {
            clone = new Node(node->val);

            std::queue<Node*> q;
            std::unordered_map<int, Node*> nodes;

            nodes[node->val] = clone;
            q.push(node);

            while (!q.empty()) {
                node = q.front();
                q.pop();

                // node is not visited
                Node* c = nodes[node->val];

                for (auto neighbor : node->neighbors) {
                    Node* n = nullptr;
                    if (nodes.find(neighbor->val) == nodes.end()) {
                        n = new Node(neighbor->val);
                        nodes[neighbor->val] = n;
                        q.push(neighbor);
                    } else {
                        n = nodes[neighbor->val];
                    }
                    c->neighbors.push_back(n);
                }
            }
        }

        return clone;
    }
};

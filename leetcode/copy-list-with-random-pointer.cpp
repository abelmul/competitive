#include <bits/stdc++.h>

using namespace std;
// Definition for a Node.
class Node
{
 public:
    int val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
 public:
    Node* copyRandomList(Node* head)
    {
        unordered_map<Node*, Node*> nodes;
        Node copy = Node(0);

        Node *ptr = head, *copy_ptr = &copy;

        while (ptr) {
            if (nodes.find(ptr) == nodes.end()) {
                nodes[ptr] = new Node(ptr->val);
            }

            if (ptr->random && nodes.find(ptr->random) == nodes.end()) {
                nodes[ptr->random] = new Node(ptr->random->val);
            }

            copy_ptr->next = nodes[ptr];
            copy_ptr->next->random = nodes[ptr->random];

            copy_ptr = copy_ptr->next;
            ptr = ptr->next;
        }

        return copy.next;
    }
};

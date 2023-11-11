#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
 public:
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> nodes;

        bool res = false;
        auto ptr = head;

        while (ptr != nullptr) {
            if (nodes.find(ptr) != nodes.end()) {
                res = true;
                break;
            }

            nodes.insert(ptr);
            ptr = ptr->next;
        }

        return res;
    }
};

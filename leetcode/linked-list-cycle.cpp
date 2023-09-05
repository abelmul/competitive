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
        auto tortoise = head;
        auto hare = head;

        while (hare && hare->next && hare->next->next) {
            hare = hare->next->next;
            tortoise = tortoise->next;

            if (hare == tortoise) {
                break;
            }
        }

        return hare && hare->next && hare->next->next;
    }
};

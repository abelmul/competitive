#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
 public:
    void reverse(ListNode* prev, ListNode* current, int size)
    {
        ListNode* ptr;

        for (auto i = 0; i < size; ++i) {
            ptr = current->next;

            current->next = ptr->next;
            ptr->next = prev->next;
            prev->next = ptr;
        }
    }

    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        ListNode dummy = ListNode(0, head);
        ListNode *ptr = head, *prev = &dummy;

        for (auto i = 0; i < left - 1; ++i, ptr = ptr->next, prev = prev->next)
            ;

        reverse(prev, ptr, right - left);

        return dummy.next;
    }
};

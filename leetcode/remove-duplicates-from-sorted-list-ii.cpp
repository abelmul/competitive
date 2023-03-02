#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
 public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* remover = nullptr;
        ListNode* new_head = nullptr;
        ListNode* now = head;
        ListNode* next;

        while (now != nullptr) {
            if (now->next != nullptr && now->next->val == now->val) {
                next = now->next;
                while (next != nullptr && next->val == now->val) {
                    next = next->next;
                }
                now = next;
            } else {
                if (remover == nullptr) {
                    new_head = now;
                    remover = new_head;
                } else {
                    remover->next = now;
                    remover = now;
                }
                now = now->next;
            }
        }
        if (remover) {
            remover->next = nullptr;
        }

        return new_head;
    }
};

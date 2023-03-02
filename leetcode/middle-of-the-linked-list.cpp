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
    ListNode* middleNode(ListNode* head)
    {
        int size = 0, half_size = 0;
        ListNode* ptr = head;

        while (ptr != nullptr) {
            ++size;
            ptr = ptr->next;
        }

        half_size = size / 2;

        ptr = head;

        while (half_size != 0) {
            ptr = ptr->next;
            --half_size;
        }

        return ptr;
    }
};

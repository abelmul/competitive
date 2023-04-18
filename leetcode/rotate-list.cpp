#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
 public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *slowptr, *fastptr;
        ListNode dummy;

        int length = 0;

        dummy = ListNode(0, head);

        fastptr = head;
        for (; fastptr; fastptr = fastptr->next) ++length;

        if (head && k % length > 0) {
            k = k % length;

            fastptr = slowptr = &dummy;

            for (; fastptr; fastptr = fastptr->next) {
                if (k <= -1) {
                    slowptr = slowptr->next;
                }
                --k;
            }

            dummy.next = slowptr->next;
            slowptr->next = nullptr;
            slowptr = dummy.next;

            while (slowptr->next) {
                slowptr = slowptr->next;
            }

            slowptr->next = head;
        }

        return dummy.next;
    }
};

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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int n = 0;
        int group_elements, extra;
        int i;
        ListNode *ptr = head, *tmp;

        vector<ListNode *> res(k, nullptr);

        for (; ptr != nullptr; ++n, ptr = ptr->next)
            ;

        group_elements = n / k, extra = n % k;
        ptr = head;
        i = 0;

        for (; ptr; ++i) {
            res[i] = ptr;
            for (auto j = 0; j < group_elements; ++j, tmp = ptr, ptr = ptr->next)
                ;

            if (extra > 0) {
                tmp = ptr;
                ptr = ptr->next;
                --extra;
            }
            tmp->next = nullptr;
        }

        return res;
    }
};

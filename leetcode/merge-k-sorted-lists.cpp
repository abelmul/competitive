#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto n = lists.size();
        ListNode *dummy, *res;

        vector<pair<int, int>> heap;
        int i;

        for (i = 0; i < n; ++i) {
            if (lists[i]) {
                heap.push_back({-lists[i]->val, i});
                push_heap(heap.begin(), heap.end());
            }
        }

        dummy = new ListNode(0);
        res = dummy;

        while (!heap.empty()) {
            i = heap.front().second;

            res->next = new ListNode(-heap.front().first);
            res = res->next;

            pop_heap(heap.begin(), heap.end());
            heap.pop_back();

            lists[i] = lists[i]->next;

            if (lists[i]) {
                heap.push_back({-lists[i]->val, i});
                push_heap(heap.begin(), heap.end());
            }
        }

        res = dummy->next;
        delete dummy;

        return res;
    }
};

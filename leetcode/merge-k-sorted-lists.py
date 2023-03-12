from heapq import heappop, heappush
from typing import List, Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        dummy = ListNode(0, None)
        min_heap = []

        ptr = dummy
        length = len(lists)

        l = lists

        # construct min heap
        for i in range(length):
            if l[i]:
                heappush(min_heap, (l[i].val, i))

        while min_heap:
            _, idx = heappop(min_heap)

            ptr.next = l[idx]
            l[idx] = l[idx].next

            ptr = ptr.next
            ptr.next = None

            if l[idx]:
                heappush(min_heap, (l[idx].val, idx))

        return dummy.next

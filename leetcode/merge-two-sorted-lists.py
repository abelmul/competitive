from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        head = None

        if list1 and list2:
            next1 = list1.next
            next2 = list2.next

            if list2.val > list1.val:
                head = list1
                head.next = self.mergeTwoLists(next1, list2)

            else:
                head = list2
                head.next = self.mergeTwoLists(list1, next2)

        return head or list1 or list2

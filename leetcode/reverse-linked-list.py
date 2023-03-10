from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        next = None

        if head:
            next = head.next
            head.next = None

        while next:
            next_ptr = next.next

            next.next = head
            head = next

            next = next_ptr

        return head

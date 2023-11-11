from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        placeholder = head
        seeker = head.next

        s = 0

        while seeker != None:
            if seeker.val == 0:
                prev = placeholder
                placeholder.val = s
                placeholder.next = seeker
                placeholder = seeker
                s = 0

            s += seeker.val
            seeker = seeker.next

        prev.next = None
        return head

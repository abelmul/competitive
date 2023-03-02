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

    def pairSum(self, head: Optional[ListNode]) -> int:
        # get the half point of list
        slow_ptr = head
        fast_ptr = head

        while fast_ptr.next and fast_ptr.next.next:
            slow_ptr = slow_ptr.next
            fast_ptr = fast_ptr.next.next

        half = slow_ptr.next
        slow_ptr.next = None

        # reverse it
        half = self.reverseList(half)

        p1 = head
        p2 = half

        max_sum = 0

        while p1 and p2:
            max_sum = max(max_sum, p1.val + p2.val)

            p1 = p1.next
            p2 = p2.next

        return max_sum

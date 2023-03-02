from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)

        lower_tail = dummy
        higher_head = None
        higher_tail = None

        ptr = head

        while ptr:
            if ptr.val < x:
                lower_tail.next = ptr
                lower_tail = ptr
            else:
                if higher_head:
                    higher_tail.next = ptr
                    higher_tail = ptr
                else:
                    higher_head = ptr
                    higher_tail = ptr

            next = ptr.next
            ptr.next = None
            ptr = next

        if higher_head:
            lower_tail.next = higher_head

        return dummy.next

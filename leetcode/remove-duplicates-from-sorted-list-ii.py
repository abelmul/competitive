from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head)

        current = dummy
        ptr = head
        next = head.next if head else None

        while next:
            if ptr.val == next.val:
                while next and ptr.val == next.val:
                    ptr = next
                    next = next.next
                current.next = next
            else:
                current.next = ptr
                current = ptr

            ptr = next
            next = next.next if next else None

        return dummy.next

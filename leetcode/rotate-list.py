from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        length = 0
        ptr = head
        while ptr:
            ptr = ptr.next
            length += 1

        if length == 0 or k % length == 0:
            return head

        k = k % length
        dummy = ListNode(0, head)

        slow_ptr = head
        fast_ptr = head

        while fast_ptr:
            # this is -1 because we need the previous node
            if k > -1:
                fast_ptr = fast_ptr.next
                k -= 1
            else:
                slow_ptr = slow_ptr.next
                fast_ptr = fast_ptr.next

        dummy.next = slow_ptr.next
        slow_ptr.next = None
        ptr = dummy.next

        while ptr.next:
            ptr = ptr.next

        ptr.next = head

        return dummy.next

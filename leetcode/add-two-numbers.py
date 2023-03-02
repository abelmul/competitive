from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        s = l1.val + l2.val
        carry = s // 10
        s %= 10

        res = ListNode(s, None)
        ptr = res

        l1 = l1.next
        l2 = l2.next

        while l1 or l2:
            n1 = l1.val if l1 else 0
            n2 = l2.val if l2 else 0

            s = n1 + n2 + carry
            carry = s // 10
            s = s % 10

            node = ListNode(s, None)

            ptr.next = node
            ptr = ptr.next

            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        if carry:
            ptr.next = ListNode(carry, None)

        return res

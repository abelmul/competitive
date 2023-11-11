# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head)

        ptr = head
        stack = []  # monotonic decreasing

        while ptr:
            while stack and ptr.val > stack[-1]:
                stack.pop()
            stack.append(ptr.val)
            ptr = ptr.next

        prev = dummy
        ptr = head
        length = len(stack)
        for i in range(length):
            ptr.val = stack[i]
            prev = ptr
            ptr = ptr.next

        prev.next = None

        return dummy.next

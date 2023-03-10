from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head)

        prev_node = dummy
        traverser = head

        while traverser:
            detached_node = traverser

            prev_node.next = traverser.next
            traverser = prev_node.next

            prev = dummy
            current = dummy.next

            while current != traverser and current.val < detached_node.val:
                prev = current
                current = current.next

            detached_node.next = current
            prev.next = detached_node

            if prev_node == prev:
                prev_node = detached_node

        return dummy.next

from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseLinkedList(self, head: Optional[ListNode]) -> Optional[ListNode]:
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

    def reverseBetween(
        self, head: Optional[ListNode], left: int, right: int
    ) -> Optional[ListNode]:
        dummy = ListNode(0, head)

        left_prev = dummy
        left_node = head
        right_node = dummy
        right_next = head

        while right > 0:
            right_node = right_next
            right_next = right_next.next

            if left > 1:
                left_prev = left_node
                left_node = left_node.next

            left -= 1
            right -= 1

        right_node.next = None

        self.reverseLinkedList(left_node)

        left_prev.next = right_node
        left_node.next = right_next

        return dummy.next

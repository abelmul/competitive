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

    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        dummy = ListNode(self, head)

        slow_ptr = head
        fast_ptr = dummy

        while fast_ptr.next and fast_ptr.next.next:
            slow_ptr = slow_ptr.next
            fast_ptr = fast_ptr.next.next

        reversed_half = self.reverseLinkedList(slow_ptr)

        ptr = head
        reverse_ptr = reversed_half

        while ptr != slow_ptr and reverse_ptr:
            if ptr.val != reverse_ptr.val:
                return False

            ptr = ptr.next
            reverse_ptr = reverse_ptr.next

        return True

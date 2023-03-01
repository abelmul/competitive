# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head and head.next:
            next = head.next
            head.next = next.next
            next.next = head

            if head.next:
                head.next = self.swapPairs(head.next)

            head = next

        return head

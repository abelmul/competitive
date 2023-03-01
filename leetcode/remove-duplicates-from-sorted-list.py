# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head)

        prev = dummy
        ptr = head
        next = head.next if head else None

        while next:
            if ptr.val == next.val:
                prev.next = next
            else:
                prev = ptr

            ptr = next
            next = ptr.next

        return dummy.next

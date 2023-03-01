# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
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

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)

        group_last = dummy
        group_next = dummy.next
        k_dup = k

        while group_next and k_dup > 0:
            group_last = group_next
            group_next = group_next.next
            k_dup -= 1

        if k_dup == 0:
            group_last.next = None

            self.reverseLinkedList(head)

            dummy.next = group_last

            if group_next:
                group_next = self.reverseKGroup(group_next, k)

            head.next = group_next

        return dummy.next

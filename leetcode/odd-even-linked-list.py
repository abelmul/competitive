# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head

        index = 1

        dummy = ListNode(0, None)

        even_nodes = ListNode(0, None)
        even_tail = even_nodes
        odd_nodes = dummy

        ptr = head

        while ptr:
            if index % 2 == 1:
                odd_nodes.next = ptr
                odd_nodes = ptr
            else:
                even_tail.next = ptr
                even_tail = ptr

            index += 1
            ptr = ptr.next

        odd_nodes.next = even_nodes.next
        even_tail.next = None

        return dummy.next

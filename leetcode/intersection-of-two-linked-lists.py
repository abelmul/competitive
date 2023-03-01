# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def getIntersectionNode(
        self, headA: ListNode, headB: ListNode
    ) -> Optional[ListNode]:

        ptra = headA
        ptrb = headB

        node_set = set()

        while ptra:
            node_set.add(ptra)
            ptra = ptra.next

        while ptrb and ptrb not in node_set:
            ptrb = ptrb.next

        return ptrb

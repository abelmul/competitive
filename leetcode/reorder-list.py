# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        li = []

        ptr = head

        while ptr:
            li.append(ptr.val)
            ptr = ptr.next

        l = 0
        r = len(li) - 1
        ptr = head

        while l < r:
            ptr.val = li[l]
            ptr.next.val = li[r]

            ptr = ptr.next.next
            l += 1
            r -= 1

        if l == r:
            ptr.val = li[l]

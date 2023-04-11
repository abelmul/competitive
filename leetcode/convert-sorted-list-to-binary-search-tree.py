from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        def middleList(head: ListNode):
            slow_ptr = ListNode(0, head)
            fast_ptr = head

            while fast_ptr.next and fast_ptr.next.next:
                slow_ptr = slow_ptr.next
                fast_ptr = fast_ptr.next.next

            half = slow_ptr.next
            slow_ptr.next = None

            return half

        def helper(head: Optional[ListNode]):
            if not head:
                return None

            middle = middleList(head)

            root = TreeNode(middle.val)
            if middle != head:
                root.left = helper(head)
            root.right = helper(middle.next)

            return root

        return helper(head)

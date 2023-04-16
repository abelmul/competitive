from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        s = 0
        stack = [root] if root else []

        while stack:
            r = stack.pop()

            if r.left:
                if not r.left.left and not r.left.right:
                    s += r.left.val
                else:
                    stack.append(r.left)
            if r.right:
                stack.append(r.right)

        return s

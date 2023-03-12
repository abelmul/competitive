from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        stack = [root]

        while stack:
            ptr = stack.pop()
            if ptr:
                res.append(ptr.val)
                stack.append(ptr.right)
                stack.append(ptr.left)

        return res

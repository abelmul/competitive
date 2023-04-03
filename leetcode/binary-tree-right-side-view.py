from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []

        left = self.rightSideView(root.left)
        right = self.rightSideView(root.right)

        if len(left) > len(right):
            for i in range(len(right), len(left)):
                right.append(left[i])

        return [root.val] + right

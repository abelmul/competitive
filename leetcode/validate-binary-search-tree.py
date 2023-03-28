from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def inOrderTraversal(root, res):
            if not root:
                return

            inOrderTraversal(root.left, res)
            res.append(root.val)
            inOrderTraversal(root.right, res)

        elements = []
        inOrderTraversal(root, elements)

        length = len(elements)

        for i in range(1, length):
            if elements[i] <= elements[i - 1]:
                return False

        return True

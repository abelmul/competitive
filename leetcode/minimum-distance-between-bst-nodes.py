from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        if root:
            for val in self.inorderTraversal(root.left):
                res.append(val)
            res.append(root.val)
            for val in self.inorderTraversal(root.right):
                res.append(val)
        return res

    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        min_diff = float("inf")

        tree = self.inorderTraversal(root)
        length = len(tree)

        for i in range(1, length):
            min_diff = min(min_diff, tree[i] - tree[i - 1])

        return int(min_diff)

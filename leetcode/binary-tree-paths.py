from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        if not root.left and not root.right:
            return [f"{root.val}"]

        right = []
        left = []

        if root.left:
            left = self.binaryTreePaths(root.left)

        if root.right:
            right = self.binaryTreePaths(root.right)

        paths = []

        for l in left:
            paths.append(f"{root.val}->{l}")
        for r in right:
            paths.append(f"{root.val}->{r}")

        return paths

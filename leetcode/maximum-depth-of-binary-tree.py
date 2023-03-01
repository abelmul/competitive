# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        max_depth = depth = 0

        nodes = []

        if root:
            nodes = [(root, 0)]

        while len(nodes) > 0:
            node, depth = nodes.pop()
            max_depth = max(max_depth, depth + 1)
            if node.left:
                nodes.append((node.left, depth + 1))

            if node.right:
                nodes.append((node.right, depth + 1))

        return max_depth

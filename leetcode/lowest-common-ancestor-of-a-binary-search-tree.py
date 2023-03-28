# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def lowestCommonAncestor(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":
        """
        This assumes both p and q are in the tree
        if the current node is p or q or if they go to different sides of the tree
        the root is the common ancestor
        """
        if (
            root == p
            or root == q
            or (root.val > p.val and root.val < q.val)
            or (root.val < p.val and root.val > q.val)
        ):
            return root

        if root.val > p.val:
            return self.lowestCommonAncestor(root.left, p, q)

        return self.lowestCommonAncestor(root.right, p, q)

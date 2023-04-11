# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        tree = []

        def inorder(root: TreeNode):
            if not root:
                return

            inorder(root.left)
            tree.append(root.val)
            inorder(root.right)

        inorder(root)

        def helper(l: int, r: int):
            if l >= r:
                return None

            m = (l + r) // 2
            root = TreeNode(tree[m])
            root.left = helper(l, m)
            root.right = helper(m + 1, r)

            return root

        return helper(0, len(tree))

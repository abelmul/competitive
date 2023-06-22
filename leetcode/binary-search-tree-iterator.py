from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BSTIterator:
    def __init__(self, root: Optional[TreeNode]):
        self.ptr = -1
        self.vals = []
        self.inOrder(root)

    def inOrder(self, node: Optional[TreeNode]):
        if node:
            self.inOrder(node.left)
            self.vals.append(node.val)
            self.inOrder(node.right)

    def next(self) -> int:
        self.ptr += 1

        return self.vals[self.ptr]

    def hasNext(self) -> bool:
        return self.ptr + 1 < len(self.vals)


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()

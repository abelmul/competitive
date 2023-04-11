from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        def helper(l: int, r: int):
            if l >= r:
                return None

            idx = l
            for i in range(l + 1, r):
                if nums[i] > nums[idx]:
                    idx = i

            root = TreeNode(nums[idx])
            root.left = helper(l, idx)
            root.right = helper(idx + 1, r)

            return root

        return helper(0, len(nums))

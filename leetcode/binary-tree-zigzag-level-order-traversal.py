from collections import deque
from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        queue = deque([root]) if root else deque()
        res = []

        current_level_elements = len(queue)
        current_level_number = 1
        current_level = []

        while current_level_elements > 0:
            node = queue.popleft()
            current_level_elements -= 1

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

            current_level.append(node.val)

            if current_level_elements == 0:
                current_level_elements = len(queue)

                if current_level_number % 2 == 0:
                    current_level.reverse()

                res.append(current_level)

                current_level_number += 1
                current_level = []

        return res

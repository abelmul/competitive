from collections import deque
from typing import Optional

"""
# Definition for a Node.
"""


class Node:
    def __init__(
        self,
        val: int = 0,
        left: Optional["Node"] = None,
        right: Optional["Node"] = None,
        next: Optional["Node"] = None,
    ):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


class Solution:
    def connect(self, root: "Node") -> "Node":
        """
        BFS
        """
        queue, prev = deque(), (root, -1)

        if root:
            queue.append((root, 0))

        while queue:
            node, level = queue.popleft()

            if level == prev[1]:
                prev[0].next = node

            prev = (node, level)

            if node.left:
                queue.append((node.left, level + 1))
            if node.right:
                queue.append((node.right, level + 1))

        return root

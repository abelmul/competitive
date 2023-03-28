from collections import deque
from heapq import heappop, heappush
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        # BFS
        queue = deque()

        level = current_sum = 0
        sums = []  # heap

        if root:
            queue.append((root, 0))

        while queue:
            node, l = queue.popleft()

            if node.left:
                queue.append((node.left, l + 1))
            if node.right:
                queue.append((node.right, l + 1))

            if l != level:
                level = l
                heappush(sums, -current_sum)
                current_sum = 0

            current_sum += node.val

        heappush(sums, -current_sum)

        res = -1
        while k > 0 and sums:
            res = heappop(sums)
            k -= 1

        return -res if k <= 0 else -1

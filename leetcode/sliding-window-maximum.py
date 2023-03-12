from collections import deque
from typing import List


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        queue = deque()
        length = len(nums)

        res = []
        for i in range(length):
            while queue and queue[-1][0] < nums[i]:
                queue.pop()

            queue.append((nums[i], i))

            if i >= k - 1:
                res.append(queue[0][0])

                if i + 1 - queue[0][1] >= k:
                    queue.popleft()

        return res

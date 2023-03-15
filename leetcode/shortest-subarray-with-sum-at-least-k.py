from collections import deque
from typing import List


class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        length = len(nums)

        # add (0,0) because we begin at 0 for presums
        min_queue = deque([(0, 0)])
        min_size = 100_001
        s = 0

        for r in range(1, length + 1):
            s += nums[r - 1]

            # monotonic increasing queue
            while min_queue and min_queue[-1][0] > s:
                min_queue.pop()

            l = -1
            while min_queue and s - min_queue[0][0] >= k:
                l = min_queue[0][1]
                min_queue.popleft()

            if l != -1:
                min_size = min(min_size, r - l)

            min_queue.append((s, r))

        return min_size if min_size <= 100_000 else -1

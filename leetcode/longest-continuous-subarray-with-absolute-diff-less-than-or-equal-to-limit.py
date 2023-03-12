from collections import deque
from typing import List


class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        min_queue = deque()
        max_queue = deque()
        length = len(nums)

        max_length = 0
        r = l = 0

        for r in range(length):
            while min_queue and nums[min_queue[-1]] > nums[r]:
                min_queue.pop()

            while max_queue and nums[max_queue[-1]] < nums[r]:
                max_queue.pop()

            min_queue.append(r)
            max_queue.append(r)

            max_length = max(max_length, r - l)

            if abs(nums[max_queue[0]] - nums[min_queue[0]]) > limit:
                l = min(min_queue[0], max_queue[0]) + 1

                if min_queue[0] > max_queue[0]:
                    max_queue.popleft()
                else:
                    min_queue.popleft()

        return max(max_length, r - l + 1)

from heapq import heapify, heappop
from typing import List


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heapify(nums)

        while len(nums) > k:
            heappop(nums)

        return heappop(nums)

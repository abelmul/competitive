from heapq import heappop, heappush
from typing import List


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        min_heap = []

        for n in nums:
            heappush(min_heap, n)
            if len(min_heap) > k:
                heappop(min_heap)

        return heappop(min_heap)

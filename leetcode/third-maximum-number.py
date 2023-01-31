from heapq import heappop, heappush
from typing import List


class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        min_heap = []
        nums_added_to_heap = set()

        for n in nums:
            if n not in nums_added_to_heap:
                heappush(min_heap, n)
                if len(min_heap) > 3:
                    heappop(min_heap)

                nums_added_to_heap.add(n)

        return heappop(min_heap) if len(min_heap) == 3 else min_heap[-1]

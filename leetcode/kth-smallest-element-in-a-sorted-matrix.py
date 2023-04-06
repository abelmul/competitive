from heapq import heappop, heappush
from typing import List


class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        min_heap = []

        for r in matrix:
            for c in r:
                heappush(min_heap, c)

        for _ in range(1, k):
            heappop(min_heap)
            k -= 1

        return heappop(min_heap)

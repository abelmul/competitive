from heapq import heapify, heappop, heappush
from typing import List


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-s for s in stones]

        heapify(stones)
        while stones:
            if len(stones) == 1:
                return -stones[0]

            one = heappop(stones)
            two = heappop(stones)

            if two != one:
                heappush(stones, one - two)

        return 0

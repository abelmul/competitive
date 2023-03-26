from typing import List


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def hours(k):
            h = 0

            for p in piles:
                h += (p - 1) // k + 1

            return h

        l, r = 1, max(piles)

        while l < r:
            k = (l + r) // 2

            if hours(k) <= h:
                r = k
            else:
                l = k + 1

        return l

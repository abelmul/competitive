from typing import List

class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        piles.sort()

        left = 0
        right = len(piles) - 1

        s = 0

        while left < right:
            left += 1  # let bob take the left pile
            right -= 1 # yours will be the left from the right most

            s += piles[right]

            right -= 1 # alice's will be the right most one

        return s

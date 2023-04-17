from typing import List


class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        m = max(candies)

        res = []

        for _, c in enumerate(candies):
            res.append(c + extraCandies >= m)

        return res

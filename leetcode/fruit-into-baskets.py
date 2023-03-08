from typing import List


class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        length = len(fruits)

        l = res = 0
        d = {}

        for r in range(length):
            d[fruits[r]] = d.get(fruits[r], 0) + 1

            while len(d.keys()) > 2:
                d[fruits[l]] -= 1
                if d[fruits[l]] <= 0:
                    del d[fruits[l]]

                l += 1

            res = max(res, r - l + 1)

        return res

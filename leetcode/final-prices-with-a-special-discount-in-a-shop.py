from typing import List


class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        min_stack = []
        res = [0] * len(prices)

        for i, p in enumerate(prices):
            res[i] = p
            while min_stack and min_stack[-1][0] >= p:
                _, j = min_stack.pop()
                res[j] = res[j] - p

            min_stack.append((p, i))

        return res

from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []

        res = [0] * len(temperatures)

        for i, t in enumerate(temperatures):
            while stack and stack[-1][1] < t:
                j, _ = stack[-1]
                res[j] = i - j
                stack.pop()

            stack.append((i, t))

        return res

from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        length = len(candidates)
        res = []

        def backtrack(l: int, cur: list, s: int):
            if s == target:
                res.append(cur.copy())
                return
            elif s > target:
                return

            for i in range(l, length):
                cur.append(candidates[i])
                backtrack(i, cur, s + candidates[i])
                cur.pop()

        backtrack(0, [], 0)

        return res

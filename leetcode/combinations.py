from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        if n < k:
            return []

        if k == 1:
            return [[i] for i in range(1, n + 1)]

        res = []

        for i in range(n, k - 1, -1):
            prevCombinations = self.combine(i - 1, k - 1)
            res += [[i] + p for p in prevCombinations]

        return res


"""
        res = []

        def backtrack(i, cur):
            if len(cur) == k:
                res.append(cur.copy())
                return

            for j in range(i, n + 1):
                # take j
                cur.append(j)
                backtrack(j+1, cur)

                # leave j
                cur.pop()

        backtrack(1, [])

        return res
"""

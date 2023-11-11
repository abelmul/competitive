from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        length = len(nums)

        res = []

        def backtrack(cur: List[int]):
            if len(cur) == length:
                res.append(cur.copy())
                return

            l = nums.copy()
            for a in l:
                nums.pop(0)
                cur.append(a)

                backtrack(cur)

                nums.append(a)
                cur.pop()

        backtrack([])

        return res

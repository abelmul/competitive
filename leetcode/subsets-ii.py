from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        length = len(nums)

        res = []

        nums.sort()

        def backtrack(l: int, cur: List[int]):
            res.append(cur.copy())
            if l >= length:
                return

            for i in range(l, length):
                if i < l + 1 or nums[i] != nums[i - 1]:
                    cur.append(nums[i])
                    backtrack(i + 1, cur)
                    cur.pop()

        backtrack(0, [])

        return res

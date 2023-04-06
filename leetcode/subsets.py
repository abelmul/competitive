from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        length = len(nums)

        def backtrack(nums: List[int], l: int, cur: List[int]):
            res.append(cur.copy())

            for i in range(l, length):
                # take nums[i]
                cur.append(nums[i])

                backtrack(nums, i + 1, cur)

                # leave nums[i]
                cur.pop()

        backtrack(nums, 0, [])

        return res

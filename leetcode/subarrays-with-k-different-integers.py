from typing import List


class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        length = len(nums)

        def countSubArraysWithAtMostK(k: int):
            d = {}
            l = 0
            res = 0

            for r in range(length):
                d[nums[r]] = d.get(nums[r], 0) + 1

                while len(d) > k:
                    d[nums[l]] -= 1

                    if d[nums[l]] <= 0:
                        del d[nums[l]]

                    l += 1

                res += r - l + 1

            return res

        return countSubArraysWithAtMostK(k) - countSubArraysWithAtMostK(k - 1)

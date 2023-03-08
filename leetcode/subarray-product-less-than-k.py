from typing import List


class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        length = len(nums)
        prod = 1
        res = l = 0

        for r in range(length):
            prod *= nums[r]

            while l <= r and prod >= k:
                prod /= nums[l]
                l += 1

            res += r - l + 1

        return res

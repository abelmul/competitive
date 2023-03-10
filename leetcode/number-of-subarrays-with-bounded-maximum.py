from typing import List


class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        length = len(nums)
        res = l = 0

        # get all subarrays that have elements < right
        for r in range(length):
            if nums[r] > right:
                l = r + 1
                continue
            res += r - l + 1

        # subtract all subarrays that have elements > left - 1
        l = 0
        for r in range(length):
            if nums[r] > left - 1:
                l = r + 1
                continue

            res -= r - l + 1

        return res

from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        length = len(nums)
        l = 0
        r = length - 1

        # get first index
        while l < r:
            m = l + (r - l) // 2

            if target > nums[m]:
                l = m + 1
            else:
                r = m

        if l >= length or nums[l] != target:
            return [-1, -1]

        first = l

        # get last index
        r = length
        while l < r:
            m = l + (r - l) // 2

            if nums[m] > target:
                r = m
            else:
                l = m + 1

        return [first, l - 1]

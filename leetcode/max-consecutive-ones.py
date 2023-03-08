from typing import List


class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        l = 0
        length = len(nums)
        res = 0

        for r in range(length):
            if nums[r] == 1:
                while nums[l] == 0:
                    l += 1
                res = max(res, r - l + 1)
            else:
                l = r

        return res

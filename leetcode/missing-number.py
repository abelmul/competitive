from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums.sort()
        length = len(nums)
        res = length

        if nums[0] != 0:
            res = 0
        else:
            for i in range(1, length):
                if nums[i] != nums[i - 1] + 1:
                    res = nums[i - 1] + 1
                    break

        return res

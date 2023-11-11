from typing import List


class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()

        length = len(nums)

        s = 0
        for i in range(0, length, 2):
            s += nums[i]

        return s

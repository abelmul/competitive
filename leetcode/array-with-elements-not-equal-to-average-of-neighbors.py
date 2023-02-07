from typing import List


class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        nums.sort()

        left = 0
        right = len(nums) - 1

        res = []

        while left < right:
            res.append(nums[left])
            res.append(nums[right])

            left += 1
            right -= 1

        if len(res) != len(nums):
            res.append(nums[left])

        return res

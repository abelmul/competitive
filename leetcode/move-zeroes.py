from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        placeholder = 0
        seeker = 0

        length = len(nums)
        seeker = 0

        while seeker < length and placeholder < length:
            if nums[placeholder] != 0:
                placeholder += 1
                seeker = placeholder + 1

            else:
                if nums[seeker] != 0:
                    nums[placeholder], nums[seeker] = nums[seeker], nums[placeholder]

                seeker += 1

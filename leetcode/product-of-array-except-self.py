from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        length = len(nums)
        prod = 1

        no_of_zeros = 0

        for i in range(length):
            if nums[i] != 0:
                prod *= nums[i]
            else:
                no_of_zeros += 1

        res = [0] * length

        if no_of_zeros <= 1:
            for i in range(length):
                n = nums[i]
                if n == 0:
                    res[i] = prod
                elif no_of_zeros == 0:
                    res[i] = prod // n

        return res

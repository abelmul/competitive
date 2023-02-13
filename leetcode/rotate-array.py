from typing import List


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        d = {}
        length = len(nums)

        for i in range(length):
            new_index = (i + k) % length

            if new_index not in d:
                d[new_index] = nums[new_index]

            nums[new_index] = d[i] if i in d else nums[i]

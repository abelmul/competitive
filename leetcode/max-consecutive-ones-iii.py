from typing import List


class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        no_of_0s = 0
        length = len(nums)
        max_length = 0

        l = 0
        for r in range(length):
            no_of_0s += 1 if nums[r] == 0 else 0
            while no_of_0s > k:
                no_of_0s -= 1 if nums[l] == 0 else 0
                l += 1

            max_length = max(max_length, r - l + 1)

        return max_length

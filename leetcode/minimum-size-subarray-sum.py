from typing import List


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        min_length = 100001  # see constraints
        length = len(nums)

        l = s = 0

        for i in range(length):
            s += nums[i]

            if s >= target:
                while s >= target:
                    s -= nums[l]
                    l += 1

                min_length = min(min_length, i - l + 2)

        if min_length > 100000:
            min_length = 0

        return min_length

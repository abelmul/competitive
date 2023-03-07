from typing import List


class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        # see constraints
        s = 0
        length = len(nums)

        for i in range(k):
            s += nums[i]

        max_average = s / k
        for i in range(k, length):
            s -= nums[i - k]
            s += nums[i]

            max_average = max(max_average, s / k)

        return max_average

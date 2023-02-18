from typing import List


class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        length = len(nums)

        max_freq = 1
        left = total = 0

        for right in range(1, length):
            total += (right - left) * (nums[right] - nums[right - 1])
            while total > k:
                total -= nums[right] - nums[left]
                left += 1

            max_freq = max(max_freq, right - left + 1)

        return max_freq

from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1

        while l <= r:
            mid = (l + r) // 2

            if mid > l and nums[mid - 1] > nums[mid]:
                return nums[mid]
            elif r > mid and nums[mid] > nums[mid + 1]:
                return nums[mid + 1]
            elif nums[l] > nums[mid]:
                r = mid - 1
            else:
                l = mid + 1

        return nums[0]

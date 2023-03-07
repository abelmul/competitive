from typing import List


class Solution:
    def binarySearch(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1

        while l <= r:
            mid = (l + r) // 2

            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                r = mid - 1
            else:
                l = mid + 1

        return -1

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        length = len(nums)
        index = self.binarySearch(nums, target)

        if index != -1:
            l = index
            r = index

            while l >= 0 and nums[l] == target:
                l -= 1

            while r < length and nums[r] == target:
                r += 1

            return [l + 1, r - 1]

        return [-1, -1]

from typing import List


class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 2
        while right >= left:
            mid = (right + left) // 2

            # if mid is even duplicate will be the next element
            # if mid is odd it will be the previous
            index = mid + 1 if mid % 2 == 0 else mid - 1

            if nums[mid] == nums[index]:
                left = mid + 1
            else:
                right = mid - 1
        return nums[left]

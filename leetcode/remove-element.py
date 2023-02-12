from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:

        l = 0
        r = len(nums) - 1

        while l <= r:
            if nums[r] == val:
                r -= 1
            elif nums[l] == val:
                nums[l] = nums[r]

                l += 1
                r -= 1
            else:
                l += 1

        return r + 1

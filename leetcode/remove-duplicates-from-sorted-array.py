from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        prev = nums[0]
        placeholder = 1
        seeker = placeholder

        length = len(nums)

        while placeholder < length and seeker < length:
            if nums[seeker] == prev:
                seeker += 1
            else:
                nums[placeholder] = nums[seeker]
                prev = nums[seeker]

                placeholder += 1
                seeker += 1

        return placeholder

from typing import List


class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        length = len(nums)

        l = res = 0

        for r in range(length):
            if nums[r] == 0:
                while nums[l] != 0:
                    l += 1
                res += r - l + 1

            else:
                l = r

        return res

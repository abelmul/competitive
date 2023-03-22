from typing import List


class Solution:
    def minMaxGame(self, nums: List[int]) -> int:
        length = len(nums)

        if length <= 2:
            return min(nums)

        res = []

        for i in range(0, length, 4):
            res.append(min(nums[i : i + 2]))
            res.append(max(nums[i + 2 : i + 4]))

        return self.minMaxGame(res)

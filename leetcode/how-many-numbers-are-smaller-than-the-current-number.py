from typing import List


class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        l = sorted(nums)
        d = {}

        for i, n in enumerate(l):
            if n not in d:
                d[n] = i

        res = [d[n] for n in nums]

        return res

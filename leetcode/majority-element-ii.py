from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        length = len(nums)
        d = {}

        res = []

        for n in nums:
            d[n] = d.get(n, 0) + 1
            if d[n] > length / 3:
                d[n] = -length
                res.append(n)

        return res

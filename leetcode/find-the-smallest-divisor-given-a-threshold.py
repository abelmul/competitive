from typing import List


class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        def getSum(divisor: int):
            res = 0
            for n in nums:
                res += (n - 1) // divisor + 1

            return res

        l = 1
        r = max(nums)

        while l < r:
            m = (l + r) // 2

            if getSum(m) > threshold:
                l = m + 1
            else:
                r = m

        return l

from typing import List


class Solution:
    def isArithmetic(self, n):
        length = len(n)

        n = sorted(n)
        diff = n[1] - n[0]

        for i in range(2, length):
            if n[i] - n[i - 1] != diff:
                return False

        return True

    def checkArithmeticSubarrays(
        self, nums: List[int], l: List[int], r: List[int]
    ) -> List[bool]:
        length = len(l)

        res = []

        for i in range(length):
            res.append(self.isArithmetic(nums[l[i] : r[i] + 1]))

        return res

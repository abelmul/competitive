from typing import List


class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        d = {0: 1}
        length = len(nums)
        res = 0

        for i in range(length):
            nums[i] += nums[i - 1] if i > 0 else 0
            diff = nums[i] % k

            if diff in d:
                res += d[diff]

            d[diff] = d.get(diff, 0) + 1

        return res

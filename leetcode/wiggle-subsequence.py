from typing import List


class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        memo = {}

        def dp(i: int, positive: bool):
            if i >= n - 1:
                return 1

            if (i, positive) not in memo:
                res = 0
                if (positive and nums[i + 1] - nums[i] < 0) or (
                    not positive and nums[i + 1] - nums[i] > 0
                ):
                    res += 1 + dp(i + 1, not positive)

                memo[(i, positive)] = max(res, dp(i + 1, positive))

            return memo[(i, positive)]

        return max(dp(0, True), dp(0, False))

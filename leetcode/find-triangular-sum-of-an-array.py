from typing import List


class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        length = len(nums)

        """
        recursive sol

        res = [0] * (length - 1)

        for i in range(1, length):
            res[i-1] = (nums[i-1] + nums[i]) % 10

        return self.triangularSum(res)
        """

        while length != 1:
            for i in range(1, length):
                nums[i - 1] = (nums[i - 1] + nums[i]) % 10

            length -= 1

        return nums[0]

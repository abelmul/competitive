from typing import List


class NumArray:
    def __init__(self, nums: List[int]):
        length = len(nums)
        self.presum = [nums[0]] * (length + 1)
        self.presum[0] = 0

        for i in range(1, length):
            self.presum[i + 1] = self.presum[i] + nums[i]

    def sumRange(self, left: int, right: int) -> int:
        return self.presum[right + 1] - self.presum[left]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)

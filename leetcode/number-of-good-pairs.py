from typing import List

class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        length = len(nums)
        count = 0

        for i,num in enumerate(nums):
            for j in range(i+1, length):
                if num == nums[j]:
                    count += 1
        return count

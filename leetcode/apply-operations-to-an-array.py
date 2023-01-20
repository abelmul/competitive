from typing import List

class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:

        n = len(nums)

        for i in range(n-1):
            if nums[i] == nums[i+1]:
                nums[i] *= 2
                nums[i+1] = 0

        count_of_zeros = 0
        li = []

        for n in nums:
            if n == 0:
                count_of_zeros += 1
            else:
                li.append(n)
        
        
        li.extend([0] * count_of_zeros)

        return li

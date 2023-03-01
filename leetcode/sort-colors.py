class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        length = len(nums)

        last_index = 0
        for i in range(length):
            if nums[i] == 0:
                nums[i], nums[last_index] = nums[last_index], nums[i]
                last_index += 1

        for i in range(length):
            if nums[i] == 1:
                nums[i], nums[last_index] = nums[last_index], nums[i]
                last_index += 1

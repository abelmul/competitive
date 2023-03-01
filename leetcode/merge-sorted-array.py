class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        cur_index = m

        for num in nums2:
            nums1[cur_index] = num
            cur_index += 1

        nums1.sort()

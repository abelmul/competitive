from typing import List


class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        s = set(nums2)

        nums1.sort()

        for n in nums1:
            if n in s:
                return n
        nums2.sort()

        if nums1[0] > nums2[0]:
            return nums2[0] * 10 + nums1[0]

        return nums1[0] * 10 + nums2[0]

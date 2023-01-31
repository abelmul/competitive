from typing import List


class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        s1 = set(nums1)
        s2 = set(nums2)

        difference = [[], []]
        for n in nums1:
            if n not in s2:
                difference[0].append(n)
                s2.add(n)

        for n in nums2:
            if n not in s1:
                difference[1].append(n)
                s1.add(n)

        return difference

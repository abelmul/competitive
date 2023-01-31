from typing import List


class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        d1 = {n: n for n in nums1}

        intersection = []
        for n in nums2:
            if n in d1:
                intersection.append(n)
                del d1[n]

        return intersection

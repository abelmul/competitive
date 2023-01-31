from typing import List


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()

        length1 = len(nums1)
        length2 = len(nums2)

        begin1, begin2 = 0, 0

        intersection = []

        while begin1 < length1 and begin2 < length2:
            if nums1[begin1] == nums2[begin2]:
                intersection.append(nums1[begin1])
                begin1 += 1
                begin2 += 1
            elif nums1[begin1] > nums2[begin2]:
                begin2 += 1
            else:
                begin1 += 1

        return intersection

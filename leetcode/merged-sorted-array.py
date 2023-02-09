from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """

        first_pointer, second_pointer = m - 1, n - 1
        i = m + n - 1

        while first_pointer >= 0 and second_pointer >= 0:
            if nums1[first_pointer] > nums2[second_pointer]:
                nums1[i] = nums1[first_pointer]
                first_pointer -= 1
            else:
                nums1[i] = nums2[second_pointer]
                second_pointer -= 1

            i -= 1

        while first_pointer >= 0:
            nums1[i] = nums1[first_pointer]
            first_pointer -= 1
            i -= 1

        while second_pointer >= 0:
            nums1[i] = nums2[second_pointer]
            second_pointer -= 1
            i -= 1

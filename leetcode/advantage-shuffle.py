from typing import List


class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        length = len(nums1)

        nums1.sort(reverse=True)
        s_nums2 = sorted([(n, i) for i, n in enumerate(nums2)], reverse=True)

        res = [0] * length

        l = 0
        r = length - 1

        for n, i in s_nums2:
            if nums1[l] > n:
                res[i] = nums1[l]
                l += 1
            else:
                res[i] = nums1[r]
                r -= 1

        return res

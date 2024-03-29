from functools import cmp_to_key
from typing import List


class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums_str = [str(n) for n in nums]

        def compare(n1, n2):
            if n1 + n2 > n2 + n1:
                return -1
            else:
                return 1

        return str(int("".join(sorted(nums_str, key=cmp_to_key(compare)))))

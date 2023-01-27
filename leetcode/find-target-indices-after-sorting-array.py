from collections import Counter
from typing import List


class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        freq = Counter(nums)

        minimum = 0
        maximum = 0

        for n in nums:
            if n > maximum:
                maximum = n
            elif n < minimum:
                minimum = n

        res = []
        index = 0

        for i in range(minimum, maximum + 1):
            if i == target:
                res = [j for j in range(index, index + freq[i])]
                break

            index += freq[i]

        return res

from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        freq = {}
        max_element = nums[0]
        for n in nums:
            freq[n] = freq.get(n, 0) + 1

            max_element = n if freq.get(max_element, 0) < freq[n] else max_element

        return max_element

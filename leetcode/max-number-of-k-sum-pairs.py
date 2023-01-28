from typing import List


class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:

        freq = {}

        max_sum = 0
        for n in nums:
            if k - n in freq:
                if freq[k - n] == 1:
                    del freq[k - n]
                else:
                    freq[k - n] -= 1
                max_sum += 1
            else:
                freq[n] = freq.get(n, 0) + 1

        return max_sum

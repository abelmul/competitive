from collections import Counter
from typing import List


class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        freq = Counter(arr)
        half = len(arr) // 2

        freq_sorted = sorted(freq.items(), key=lambda d: d[1], reverse=True)

        s = 0
        removed = 0
        for _, v in freq_sorted:
            if s >= half:
                break
            s += v
            removed += 1

        return removed

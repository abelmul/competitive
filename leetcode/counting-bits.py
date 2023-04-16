from typing import List


class Solution:
    def countBits(self, n: int) -> List[int]:
        res = [0] * (n + 1)

        for i in range(1, n + 1):
            # Brian Kernighan's algorithm
            res[i] = 1 + res[i & i - 1]

        return res

from typing import List


class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        index = 0
        odds = 0
        evens = 0

        while n:
            if index & 1:
                odds += n & 1
            else:
                evens += n & 1

            n = n >> 1
            index += 1

        return [evens, odds]

from typing import List


class Solution:
    def invert(self, s: List[str]) -> List[str]:
        for i in range(len(s)):
            s[i] = "0" if s[i] == "1" else "1"

        return s

    def binary_string(self, n: int) -> List[str]:
        if n == 1:
            return ["0"]

        s = self.binary_string(n - 1)

        return s + ["1"] + self.invert(s)[::-1]

    def findKthBit(self, n: int, k: int) -> str:
        return self.binary_string(n)[k - 1]

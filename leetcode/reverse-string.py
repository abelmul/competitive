from typing import List


class Solution:
    def helper(self, s: List[str], i, j) -> None:
        if not s or i >= j or j - i == 1:
            return

        s[i], s[j - 1] = s[j - 1], s[i]

        self.helper(s, i + 1, j - 1)

    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """

        self.helper(s, 0, len(s))

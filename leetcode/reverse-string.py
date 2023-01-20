from typing import List

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """

        # s.reverse()
        negative_i = -1
        length = len(s)
        for i in range(length):
            if i >= length + negative_i:
                break

            s[i], s[negative_i] = s[negative_i], s[i]

            negative_i -= 1

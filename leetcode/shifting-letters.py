from typing import List


class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        length = len(shifts)
        for i in range(length - 2, -1, -1):
            shifts[i] += shifts[i + 1]

        return "".join(
            [chr((ord(s[i]) - 97 + shifts[i]) % 26 + 97) for i in range(length)]
        )

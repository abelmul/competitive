from typing import List


class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        li = list(s)
        length = len(s)
        delta = [0] * (length + 1)

        for st, e, d in shifts:
            delta[st] += 1 if d == 1 else -1
            delta[e + 1] -= 1 if d == 1 else -1

        for i in range(1, length + 1):
            delta[i] += delta[i - 1]

        for i in range(length):
            li[i] = chr((ord(li[i]) - 97 + delta[i]) % 26 + 97)

        return "".join(li)

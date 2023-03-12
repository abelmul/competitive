class Solution:
    def firstUniqChar(self, s: str) -> int:
        letters = [0] * 26

        for c in s:
            letters[ord(c) - 97] += 1

        for i, c in enumerate(s):
            if letters[ord(c) - 97] == 1:
                return i

        return -1

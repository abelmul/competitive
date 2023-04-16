class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        c = 0

        for i in range(len(s)):
            c = c ^ ord(t[i]) ^ ord(s[i])

        return chr(c ^ ord(t[-1]))

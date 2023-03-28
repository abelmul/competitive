class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        length = len(s)

        while length >= 0:
            if s[length - 1] != " ":
                break
            length -= 1

        res = 0
        while length - res - 1 >= 0:
            if s[length - res - 1] == " ":
                break
            res += 1

        return res

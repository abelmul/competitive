class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if s != "":
            for i in t:
                if i == s[0]:
                    s = s[1:]
                    if s == "":
                        break

        return s == ""

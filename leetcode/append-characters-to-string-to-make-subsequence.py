class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        count = len(t)
        if s != "":
            for i in s:
                if i == t[0]:
                    t = t[1:]
                    if t == "":
                        break
            count = len(t)

        return count

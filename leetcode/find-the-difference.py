class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        l = list(t)

        for i in s:
            l.remove(i)

        return l[0]

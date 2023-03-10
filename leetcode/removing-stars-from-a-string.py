class Solution:
    def removeStars(self, s: str) -> str:
        li = []
        for c in s:
            if c == "*":
                li.pop()
            else:
                li.append(c)

        return "".join(li)

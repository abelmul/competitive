class Solution:
    def isValid(self, s: str) -> bool:
        li = []

        h = {")": "(", "}": "{", "]": "["}

        for c in s:
            if c in h.keys():
                if not li or li[-1] != h[c]:
                    return False
                li.pop()
            else:
                li.append(c)

        return len(li) == 0

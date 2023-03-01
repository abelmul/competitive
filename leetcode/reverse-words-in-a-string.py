class Solution:
    def reverseWords(self, s: str) -> str:
        li = s.split()

        l = 0
        r = len(li) - 1

        while l < r:
            li[l], li[r] = li[r], li[l]

            l += 1
            r -= 1

        return " ".join(li)

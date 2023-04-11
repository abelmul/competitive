from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def backtrack(s: str, l: int, r: int):
            if r == l == 0:
                res.append(s)
                return

            if l > 0:
                backtrack(s + "(", l - 1, r)

            if r > l:
                backtrack(s + ")", l, r - 1)

        backtrack("", n, n)

        return res

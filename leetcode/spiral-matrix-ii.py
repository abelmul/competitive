from typing import List


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0] * n for _ in range(n)]
        elems = iter(range(1, n * n + 1))

        rows = columns = n
        r = c = 0

        while r < rows and c < columns:
            # →
            for i in range(c, columns):
                res[r][i] = next(elems)
            r += 1

            # ↓
            for i in range(r, rows):
                res[i][columns - 1] = next(elems)
            columns -= 1

            # ←
            if r < rows:
                for i in range(columns - 1, c - 1, -1):
                    res[rows - 1][i] = next(elems)
                rows -= 1

            # ↑
            if c < columns:
                for i in range(rows - 1, r - 1, -1):
                    res[i][c] = next(elems)
                c += 1

        return res

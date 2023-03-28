from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])

        def traverseRow(row, r, result):
            for i in r:
                result.append(matrix[row][i])

        def traverseColumn(column, r, result):
            for i in r:
                result.append(matrix[i][column])

        res = []
        r = 0
        c = 0

        reverse = False

        while r < m and c < n:
            if reverse:
                traverseRow(m - 1, range(n - 1, c - 1, -1), res)
                m -= 1

                traverseColumn(c, range(m - 1, r - 1, -1), res)
                c += 1
            else:
                traverseRow(r, range(c, n), res)
                r += 1

                traverseColumn(n - 1, range(r, m), res)
                n -= 1

            reverse = not reverse
        return res

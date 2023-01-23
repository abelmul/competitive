from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)

        row = m // 2 - 1

        while row >= 0 and row < m - 1:
            if matrix[row][0] <= target and matrix[row + 1][0] > target:
                break

            elif matrix[row][0] > target:
                row -= 1

            elif matrix[row][0] < target:
                row += 1

        return target in matrix[row]

from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])

        # find row
        row = l = 0
        r = m - 1

        # search for row
        while l <= r:
            row = l + (r - l) // 2

            if matrix[row][0] > target:
                r = row - 1
            elif target > matrix[row][-1]:
                l = row + 1
            else:
                # we found the row
                break

        # search for column
        if row < m:
            l = 0
            r = n - 1

            while l <= r:
                column = l + (r - l) // 2

                if matrix[row][column] > target:
                    r = column - 1
                elif target > matrix[row][column]:
                    l = column + 1
                else:
                    return True

        return False

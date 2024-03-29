from typing import List


class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        rows = len(matrix)
        columns = len(matrix[0])

        self.presum = [[0 for _ in range(columns + 1)] for _ in range(rows + 1)]

        for r in range(rows):
            for c in range(columns):
                self.presum[r + 1][c + 1] = (
                    matrix[r][c]
                    + self.presum[r][c + 1]
                    + self.presum[r + 1][c]
                    - self.presum[r][c]
                )

        print(self.presum)

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return (
            self.presum[row2 + 1][col2 + 1]
            - self.presum[row2 + 1][col1]
            - self.presum[row1][col2 + 1]
            + self.presum[row1][col1]
        )


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)

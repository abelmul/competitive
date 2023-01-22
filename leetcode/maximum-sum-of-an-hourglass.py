from typing import List


class Solution:
    def maxSum(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        columns = len(grid[0])

        hourglass_sum = 0

        for r in range(rows - 2):
            for c in range(columns - 2):
                hourglass_sum = max(
                    hourglass_sum,
                    grid[r][c]
                    + grid[r][c + 1]
                    + grid[r][c + 2]
                    + grid[r + 1][c + 1]
                    + grid[r + 2][c]
                    + grid[r + 2][c + 1]
                    + grid[r + 2][c + 2],
                )

        return hourglass_sum

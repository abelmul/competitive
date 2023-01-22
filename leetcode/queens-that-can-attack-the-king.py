from typing import List

class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:

        queens_set = set(tuple(q) for q in queens)
        direction = [
            (-1,-1), (-1, 0), (-1, 1),
            (0, -1),          (0, 1),
            (1,-1),  (1, 0),  (1, 1)
        ]

        attacking_queens = []

        for d in direction:
            row, column = king

            while row >= 0 and row < 8 and column >= 0 and column < 8:
                row += d[0]
                column += d[1]
                if (row, column) in queens_set:
                    attacking_queens.append([row, column])
                    break

        return attacking_queens

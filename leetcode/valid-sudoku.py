from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def isValid(r1, r2, c1, c2):
            hash = {
                "1": 0,
                "2": 0,
                "3": 0,
                "4": 0,
                "5": 0,
                "6": 0,
                "7": 0,
                "8": 0,
                "9": 0,
            }

            for r in range(r1, r2):
                for c in range(c1, c2):
                    if board[r][c] != ".":
                        hash[board[r][c]] += 1

                        if hash[board[r][c]] > 1:
                            return False

            return True

        """
        since we only check 9 cells per row, 9 cells per column and 9 cells per box

        the time and space complexity is O(1)
        """
        for i in range(9):
            r = i // 3
            c = i % 3

            if not (
                isValid(i, i + 1, 0, 9)
                and isValid(0, 9, i, i + 1)
                and isValid(r * 3, (r * 3) + 3, c * 3, (c * 3) + 3)
            ):
                return False

        return True

from typing import List


class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        row = len(matrix)
        column = len(matrix[0])

        transpose = [[matrix[j][i] for j in range(row)] for i in range(column)]

        return transpose

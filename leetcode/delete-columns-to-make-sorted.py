from typing import List


class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n = len(strs)
        length = len(strs[0])

        str_matrix: List[List[str | int]] = [[0] * n for _ in range(length)]
        for i in range(length):
            for j in range(n):
                str_matrix[i][j] = strs[j][i]

        count = 0
        for i in range(length):
            if sorted(str_matrix[i]) != str_matrix[i]:
                count += 1

        return count

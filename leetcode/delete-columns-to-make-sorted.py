from typing import List


class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n = len(strs)
        length = len(strs[0])

        str_matrix = [[strs[j][i] for j in range(n)] for i in range(length)]

        count = 0
        for i in range(length):
            if sorted(str_matrix[i]) != str_matrix[i]:
                count += 1

        return count

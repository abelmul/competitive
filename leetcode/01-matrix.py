from collections import deque
from typing import List


class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        n, m = len(mat), len(mat[0])
        dirs = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        res = [[0] * m for _ in range(n)]

        queue = deque()
        prev = {}

        for i in range(0, n):
            for j in range(0, m):
                if mat[i][j] == 0:
                    queue.append((i, j))
                    prev[(i, j)] = 0

        while queue:
            row, col = queue.popleft()

            for d in dirs:
                r = row + d[0]
                c = col + d[1]
                if r >= 0 and r < n and c >= 0 and c < m and (r, c) not in prev:
                    prev[(r, c)] = prev[(row, col)] + 1
                    queue.append((r, c))
                    res[r][c] = prev[(r, c)]

        return res

"""
Beautiful Grid

https://codeforces.com/gym/422879/problem/E

Time - O(n^2)
Space - O(1)
"""

t = int(input())

for _ in range(t):
    n = int(input())

    matrix = [list(map(int, list(input()))) for _ in range(n)]
    minimum_ops = 0

    for i in range(n):
        for j in range(n):
            s = (
                matrix[i][j]
                + matrix[j][n - i - 1]
                + matrix[n - i - 1][n - j - 1]
                + matrix[n - j - 1][i]
            )

            if s == 1 or s == 3:
                minimum_ops += 1
            elif s == 2:
                minimum_ops += 2

    print(minimum_ops // 4)

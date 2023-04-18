"""
Can you find the Bishop? 

https://codeforces.com/gym/422879/problem/C

Time - O(1)
Space - O(1)
"""

t = int(input())

grid = []

for i in range(t):
    input()
    row, column = 0, 0

    for j in range(8):
        s = input()
        if i == 3:
            # print(s)
            pass

        grid.append(list(s))

    for r in range(1, 7):
        if row != 0:
            break
        for c in range(1, 7):
            if grid[r][c] == grid[r - 1][c - 1] == grid[r - 1][c + 1] == "#":
                row, column = r + 1, c + 1
                break

    grid = []

    print(row, column)

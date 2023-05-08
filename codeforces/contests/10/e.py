"""
Seat Arrangements 

https://codeforces.com/gym/430578/problem/E

Time - O(n^2)
Space - O(1)
"""

n, m, k = map(int, input().split())
res = 0

seats = []

for _ in range(n):
    seats.append(input()[:m])

# check rows
for i in range(n):
    k_row = 0
    for j in range(m):
        if seats[i][j] == ".":
            k_row += 1
        else:
            if k_row >= k:
                res += k_row - k + 1
            k_row = 0

    if k_row >= k:
        res += k_row - k + 1

# check columns
for j in range(m):
    k_col = 0
    for i in range(n):
        if seats[i][j] == ".":
            k_col += 1
        else:
            if k_col >= k:
                res += k_col - k + 1
            k_col = 0

    if k_col >= k:
        res += k_col - k + 1

if k == 1:
    res = res >> 1

print(res)

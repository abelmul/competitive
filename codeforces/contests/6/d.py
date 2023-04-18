"""
New Sorting

https://codeforces.com/gym/425122/problem/D

Time - O(nlog(n))
Space - O(1)
"""

n = int(input())
a = list(map(int, input().split()))[:n]

a.sort()

for i in range(1, n):
    iseven = (i + 1) % 2 == 0

    if not iseven and a[i] > a[i - 1]:
        a[i - 1], a[i] = a[i], a[i - 1]

print(*a)

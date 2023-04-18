"""
Spend Less Money 

https://codeforces.com/gym/429357/problem/D

Time - O(nlog(n))
Space - O(n)
"""

from typing import List, Tuple

n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

diff_array: List[Tuple[int, int]] = [(0, 0)] * n

for i in range(n):
    diff_array[i] = (i, a[i] - b[i])

diff_array = sorted(diff_array, key=lambda d: d[1])

total = 0

for i in range(n):
    j = diff_array[i][0]
    total += a[j] if i < k or diff_array[i][1] < 0 else b[j]

print(total)

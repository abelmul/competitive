"""
SwapSort

https://codeforces.com/gym/430578/problem/D

Time - O(n)
Space - O(n)
"""

n = int(input())
a = list(map(int, input().split()))
swaps = []

for i in range(n):
    min_index = i
    for j in range(i, n):
        if a[min_index] > a[j]:
            min_index = j

    a[i], a[min_index] = a[min_index], a[i]

    if i != min_index:
        swaps.append((i, min_index))

print(len(swaps))

for s in swaps:
    print(*s)

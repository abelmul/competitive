"""
Problem 5

https://codeforces.com/gym/421700/problem/D

Time - O(nlog(n))
Space - O(n)
"""

n, l = [int(i) for i in input().split()]
a = sorted(map(int, input().split()))

min_radius = max(a[0], l - a[-1])

for i in range(1, n):
    min_radius = max(min_radius, ((a[i] - a[i - 1]) / 2))

print(min_radius)

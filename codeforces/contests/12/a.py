"""
Queue

https://codeforces.com/gym/432138/problem/A

Time - O(n)
Space - O(1)
"""

n = int(input())
a = list(map(int, input().split()))

a.sort()

res = 0
total = 0

for i in range(n):
    if total <= a[i]:
        total += a[i]
        res += 1

print(res)

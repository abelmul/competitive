"""
New Year Transportation 

https://codeforces.com/gym/444629/problem/A

Time - O(n)
Space - O(1)
"""

n, t = map(int, input().split())

a = list(map(int, input().split()))

res = "NO"

i = 0
while i < n - 1:
    if t == i + 1:
        res = "YES"
        break
    i += a[i]

if t == i + 1:
    res = "YES"

print(res)

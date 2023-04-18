"""
Mahmoud and a Triangle

https://codeforces.com/gym/424233/problem/D

Time - O(nlog(n))
Space - O(n)
"""

n = int(input())
a = sorted(list(map(int, input().split())), reverse=True)

res = "NO"

for i in range(n - 2):
    if a[i] < a[i + 1] + a[i + 2]:
        res = "YES"
        break

print(res)

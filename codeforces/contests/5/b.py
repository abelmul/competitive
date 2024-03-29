"""
Dragons

https://codeforces.com/gym/424233/problem/B

Time - O(nlog(n))
Space - O(n)
"""

s, n = map(int, input().split())

res = "YES"

dragons = sorted(
    [tuple(map(int, input().split())) for _ in range(n)], key=lambda t: t[0]
)

res = "YES"
for d in dragons:
    x, y = d

    if x >= s:
        res = "NO"
        break
    s += y

print(res)

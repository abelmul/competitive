"""
Page Numbers

https://codeforces.com/gym/429357/problem/C

Time - O(nlog(n))
Space - O(1)
"""

a = list(map(int, input().split(",")))

a.sort()

n = len(a)
l = 0
cur = 0
r = 0

res = []

while r < n:
    if a[cur] == a[r] or a[r] - a[cur] == 1:
        cur = r
    else:
        res.append(f"{a[l]}-{a[cur]}" if a[l] != a[cur] else f"{a[l]}")
        l = r
        cur = r

    r += 1

res.append(f"{a[l]}-{a[cur]}" if a[l] != a[cur] else f"{a[l]}")
print(",".join(res))

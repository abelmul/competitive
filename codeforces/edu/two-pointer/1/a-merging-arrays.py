n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

ai = 0
bi = 0

res = []

while ai < n or bi < m:
    next_element = float("inf")

    if bi == m or (ai < n and a[ai] < b[bi]):
        res.append(a[ai])
        ai += 1
    else:
        res.append(b[bi])
        bi += 1

print(*res)

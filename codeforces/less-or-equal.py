n, k = map(int, input().split())
a = list(map(int, input().split()))

a.sort()

res = -1

if k == 0:
    if a[0] > 1:
        res = a[0] - 1
elif k == n:
    res = a[-1]
elif a[k - 1] != a[k]:
    res = a[k - 1]

print(res)

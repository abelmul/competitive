n, m = map(int, input().split())
a = list(map(int, input().split()))[:n]

a.sort()

max_sum = 0
for i in range(m):
    if a[i] >= 0:
        break
    max_sum += a[i]

print(-max_sum)

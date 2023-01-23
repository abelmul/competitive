n, k = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
t = [int(i) for i in input().split()]

minutes = 0
for i in range(n):
    minutes += t[i] * a[i]

for i in range(k):
    if t[i] == 0:
        minutes += a[i]

# use sliding window to calculate maximum minutes
max_minutes = minutes

for i in range(k, n):
    if t[i] == 0:
        minutes += a[i]
    if t[i - k] == 0:
        minutes -= a[i - k]

    max_minutes = max(max_minutes, minutes)

print(max_minutes)

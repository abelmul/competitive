n = int(input())

intervals = []
for i in range(n):
    intervals.append(tuple(map(int, input().split())))

intervals.sort()

count = 0
interval = intervals[0]

for i in range(1, n):
    current_interval = intervals[i]
    if interval[0] < current_interval[0] and interval[1] > current_interval[1]:
        continue

    count += 1
    interval = current_interval

count += 1
print(n - count)

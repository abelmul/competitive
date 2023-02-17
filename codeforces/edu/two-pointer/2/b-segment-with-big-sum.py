n, s = map(int, input().split())
a = list(map(int, input().split()))

min_elems = float("inf")
current_sum = left = 0

for right in range(n):
    current_sum += a[right]

    while current_sum - a[left] >= s:
        current_sum -= a[left]
        left += 1

    min_elems = min(min_elems, right - left + 1) if current_sum >= s else min_elems

print(min_elems if min_elems != float("inf") else -1)

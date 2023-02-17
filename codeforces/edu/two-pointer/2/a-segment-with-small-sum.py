n, s = map(int, input().split())
a = list(map(int, input().split()))

max_elems = current_sum = right = 0

for left in range(n):
    while right < n and current_sum + a[right] <= s:
        current_sum += a[right]
        right += 1

    current_sum -= a[left]
    max_elems = max(max_elems, right - left)

print(max_elems)

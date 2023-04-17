"""
Sereja and Dima

https://codeforces.com/gym/431213/problem/A

Time - O(n)
Space - O(1)
"""

n = int(input())
a = list(map(int, input().split()))

l = 0
r = n - 1

sereja_sum = 0
dima_sum = 0

sereja_move = True

while l <= r:
    if sereja_move:
        if a[l] > a[r]:
            sereja_sum += a[l]
            l += 1
        else:
            sereja_sum += a[r]
            r -= 1
    else:
        if a[l] > a[r]:
            dima_sum += a[l]
            l += 1
        else:
            dima_sum += a[r]
            r -= 1

    sereja_move = not sereja_move

print(sereja_sum, dima_sum)

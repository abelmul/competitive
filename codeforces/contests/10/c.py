"""
Make Product Equal One 

https://codeforces.com/gym/430578/problem/C

Time - O(n)
Space - O(1)
"""

n = int(input())

a = list(map(int, input().split()))

added = 0
neg_count = 0
zero_count = 0

for i in range(n):
    if a[i] < -1:
        added += -1 - a[i]
        a[i] = -1
        neg_count += 1
    elif a[i] == -1:
        neg_count += 1
    elif a[i] == 0:
        zero_count += 1
    elif a[i] > 1:
        added += a[i] - 1

if neg_count % 2 == 1:
    if zero_count != 0:
        zero_count -= 1
        added += 1
    else:
        added += 2

added += zero_count

print(added)

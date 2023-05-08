"""
Choose Min Subsegment

https://codeforces.com/gym/428258/problem/E

Time - O(n^2)
Space - O(n)
"""
from collections import defaultdict

n = int(input())

a = list(map(int, input().split()))

min_sub = n - 1
df = defaultdict(lambda: 0)

for i in range(n):
    valid = True

    for j in range(i):
        df[a[j]] += 1
        if df[a[j]] > 1:
            valid = False
            break

    if not valid:
        break

    idx = n
    for j in range(n - 1, i - 1, -1):
        df[a[j]] += 1

        if df[a[j]] > 1:
            break
        idx = j

    min_sub = min(min_sub, idx - i)

    df.clear()

print(min_sub)

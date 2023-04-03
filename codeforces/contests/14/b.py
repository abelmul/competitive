"""
Queries about less or equal elements 

https://codeforces.com/gym/434753/problem/B

time = O(mlog(n))
space = O(m)
"""

n,m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

# sort array
a.sort()

def binarySearch(a, q):
    l = 0
    r = len(a)

    while l < r:
        m = (l + r) // 2

        if a[m] > q:
            r = m
        else:
            l = m + 1

    return l

res = [0] * m
for i in range(m):
    res[i] = binarySearch(a, b[i])

print(*res)

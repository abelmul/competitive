"""
Reorder the Array

https://codeforces.com/gym/428258/problem/B

Time - O(nlog(n))
Space - O(n)
"""

n = int(input())
a = list(map(int, input().split()))

a.sort()

if sum(a[:n]) == sum(a[n:]):
    print(-1)
else:
    print(*a)

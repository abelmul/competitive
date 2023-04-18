"""
Yared's Problem

https://codeforces.com/gym/433100/problem/B

Time - O(logn)
Space - O(n)
"""

for _ in range(int(input())):
    n = int(input())
    a = sorted(map(int, input().split()))

    res = "YES"
    for i in range(1, n):
        if a[i] - a[i - 1] > 1:
            res = "NO"
            break

    print(res)

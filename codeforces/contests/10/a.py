"""
Advantage

https://codeforces.com/gym/430578/problem/A

Time - O(nlog(n))
Space - O(n)
"""

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    res = a
    a = sorted(a)

    for i in range(n):
        res[i] = res[i] - a[-1]
        if res[i] == 0:
            res[i] = a[-1] - a[-2]

    print(*res)

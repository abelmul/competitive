"""
Good Subarrays

https://codeforces.com/gym/431213/problem/E

Time - O(n)
Space - O(n)
"""

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input()))

    d = {0: 1}
    acc = 0
    res = 0

    for i in range(n):
        acc += a[i]

        diff = acc - i - 1
        res += d.get(diff, 0)
        d[diff] = d.get(diff, 0) + 1

    print(res)

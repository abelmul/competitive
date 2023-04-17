"""
Ternary String

https://codeforces.com/gym/431213/problem/B

Time - O(n)
Space - O(1)
"""

for _ in range(int(input())):
    s = input()

    n = len(s)
    d = {}
    l = 0

    res = 200001  # see constraints

    for r in range(n):
        d[s[r]] = r

        if d.keys() == {"1", "2", "3"}:
            l = min(d.values())
            res = min(res, r - l + 1)

    print(0 if res > 200000 else res)

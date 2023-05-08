"""
Nice Word

https://codeforces.com/gym/428258/problem/D

Time - O(n)
Space - O(n)
"""

from string import ascii_uppercase

s = list(input())
n = len(s)

res = -1

if n >= 26:
    for i in range(n - 25):
        st = s[i : i + 26]

        dup = False
        d = {}

        for c in ascii_uppercase:
            d[c] = 0

        for c in st:
            d[c] = d.get(c, 0) + 1
            if c != "?" and d[c] > 1:
                dup = True
                break

        if dup:
            continue

        remaining = list(filter(lambda p: p[1] == 0, d.items()))

        for j in range(26):
            if st[j] == "?":
                st[j] = remaining.pop()[0]

        if len(remaining) == 0:
            res = "".join(s[:i]).replace("?", "A")
            res += "".join(st)
            res += "".join(s[i + 26 :]).replace("?", "A")

            break

print(res)

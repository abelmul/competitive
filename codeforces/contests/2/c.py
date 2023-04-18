"""
Dakti

https://codeforces.com/gym/420178/problem/C

Time - O(n)
Space - O(n)
"""

from typing import Any

n = int(input())

for i in range(n):
    sentense = input().split()

    chorus: Any = [None] * len(sentense)

    for s in sentense:
        letter = []
        digit = []
        for j, c in enumerate(s):
            if c.isdigit():
                digit.append(c)
            else:
                letter.append(c)
        chorus[int("".join(digit)) - 1] = "".join(letter)

    print(" ".join(chorus))

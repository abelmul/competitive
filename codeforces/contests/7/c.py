"""
Prepend and Append

https://codeforces.com/gym/426951/problem/C

Time - O(n)
Space - O(1)
"""

t = int(input())

for _ in range(t):
    n = int(input())
    s = input()

    l = 0
    r = n - 1

    while l < r:
        if (s[l] == "0" and s[r] == "1") or (s[l] == "1" and s[r] == "0"):
            l += 1
            r -= 1
            continue

        break

    print(r - l + 1)

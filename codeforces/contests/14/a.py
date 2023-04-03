"""
Word

https://codeforces.com/gym/434753/problem/A

time = O(logn)
space = O(1)
"""

s = input()

s_sorted = sorted(list(s))

l = 0
r = len(s)

while l < r:
    m = (l + r) // 2

    if s_sorted[m] >= 'a': 
        # is capital
        r = m
    else:
        l = m + 1

if l > len(s) - r:
    print(s.upper())
else:
    print(s.lower())

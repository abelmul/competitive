"""
Problem 1

https://codeforces.com/gym/421700/problem/A

Time - O(n)
Space - O(1)
"""

n = int(input())

for i in range(n):
    w = input()
    if len(w) > 10:
        print(f"{w[0]}{len(w)-2}{w[-1]}")
    else:
        print(w)

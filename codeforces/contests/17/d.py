"""
Twitter joke

https://codeforces.com/gym/438582/problem/D

Time - O(n)
Space - O(n)
"""

n = int(input())

depth = {"polycarp": 1}
max_depth = 1

for i in range(n):
    s = input().split()

    depth[s[0].lower()] = depth[s[2].lower()] + 1
    max_depth = max(max_depth, depth[s[0].lower()])

print(max_depth)

"""
Vasya's Amazing Contests 

https://codeforces.com/gym/420178/problem/B

Time - O(nlog(n))
Space - O(n)
"""

n = int(input())
s = input().split()

li = []
amazing_count = 0

for i in range(n):
    z = int(s[i])

    if len(li) > 0 and (z < li[0] or z > li[-1]):
        amazing_count += 1

    li.append(z)
    li.sort()

print(amazing_count)

"""
A2SVians
https://codeforces.com/gym/419273/problem/D

Time - O(n)
Space - O(n)
"""

n = int(input())

names = set(input().split(" "))

names_flagged_bad = set(input().split(" "))

not_bad_names = names - names_flagged_bad

excellent_members = 0

for name in not_bad_names:
    if len(name) % len(set(name)) == 0:
        excellent_members += 1
print(excellent_members)

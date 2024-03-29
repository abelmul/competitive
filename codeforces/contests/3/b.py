"""
Problem 2

https://codeforces.com/gym/421700/problem/B

Time - O(n)
Space - O(1)
"""

first_string = input().lower()
second_string = input().lower()

res = "0"

for i, f in enumerate(first_string):
    if f < second_string[i]:
        res = -1
        break
    elif f > second_string[i]:
        res = 1
        break

print(res)

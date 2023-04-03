"""
A pile of stones 

https://codeforces.com/gym/436386/problem/A

time = O(n)
space = O(1)
"""

n = int(input())

s = input()

res = 0

for i in range(n):
    if s[i] == "-" and res > 0:
        res -= 1
    elif s[i] == "+":
        res += 1

print(res)

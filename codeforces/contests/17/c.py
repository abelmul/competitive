"""
Long Valid Parenthesis 

https://codeforces.com/gym/438582/problem/C

Time - O(n)
Space - O(n)
"""

s = input().strip()
stack = []
removed = 0

for c in s:
    if c == ")":
        if not stack:
            removed += 1
        else:
            stack.pop()
    else:
        stack.append(c)

print(len(s) - removed - len(stack))

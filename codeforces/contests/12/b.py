"""
Plug-in

https://codeforces.com/gym/432138/problem/B

Time - O(n)
Space - O(n)
"""

s = input().strip()

stack = []

for c in s:
    if stack and stack[-1] == c:
        stack.pop()
    else:
        stack.append(c)

print("".join(stack))

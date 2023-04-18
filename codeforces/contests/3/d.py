"""
Problem 4

https://codeforces.com/gym/421700/problem/D

Time - O(n)
Space - O(1)
"""

hello = "hello"
h = input()

index = 0
for c in h:
    if hello[index] == c:
        index += 1
        if index >= len(hello):
            break

print("YES" if index >= len(hello) else "NO")

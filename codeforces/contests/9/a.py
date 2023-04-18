"""
Add Opposite Values 

https://codeforces.com/gym/429357/problem/A

Time - O(n)
Space - O(1)
"""

t = int(input())

for _ in range(t):
    n = int(input())
    s = input()

    l = 0
    r = n - 1

    while l < r and s[l] != s[r]:
        l += 1
        r -= 1

    print(r - l + 1)

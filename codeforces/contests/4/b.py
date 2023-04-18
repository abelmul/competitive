"""
Cut Square

https://codeforces.com/gym/422879/problem/B

Time - O(1)
Space - O(1)
"""

t = int(input())

for i in range(t):
    a1, b1 = map(int, input().split())
    a2, b2 = map(int, input().split())

    if max(a1, b1) == max(a2, b2) and min(a1, b1) + min(a2, b2) == max(a1, b1):
        print("YES")
    else:
        print("NO")

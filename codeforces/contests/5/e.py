"""
No Zeros

https://codeforces.com/gym/424233/problem/E

Time - O(nlog(n))
Space - O(1)
"""

for i in range(int(input())):
    n = int(input())

    a = list(map(int, input().split()))
    s = sum(a)

    if s == 0:
        print("NO")
    else:
        print("YES")
        if s > 0:
            print(*sorted(a, reverse=True))
        else:
            print(*sorted(a))

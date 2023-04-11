"""
Traffic Light
https://codeforces.com/gym/418150/problem/E

Time - O(n)
Space - O(n)
"""

t = int(input())

for i in range(t):
    li = input().split(" ")

    n = int(li[0])
    c = li[1]

    s = input() * 2

    if c == "g":
        print(0)

    else:
        cidx = []
        gidx = []

        for i, v in enumerate(s):
            if v == "g":
                gidx.append(i)
            elif i < n and v == c:
                cidx.append(i)
        j = 0
        max_time = 0
        for i in cidx:
            while i >= gidx[j]:
                j += 1
            max_time = max(max_time, gidx[j] - i)

        print(max_time)

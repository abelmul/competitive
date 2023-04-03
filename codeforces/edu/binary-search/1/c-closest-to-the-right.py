"""
https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C

723ms 9.5mb

time - O(log n)
space - O(1) / without input
"""
n, k = map(int, input().split())
a = list(map(int, input().split()))
q = list(map(int, input().split()))


def bisect_right(a, t):
    l = 0
    r = len(a)

    while l < r:
        m = (l + r) // 2

        if t <= a[m]:
            r = m
        else:
            l = m + 1

    return l


for t in q:
    print(bisect_right(a, t) + 1)

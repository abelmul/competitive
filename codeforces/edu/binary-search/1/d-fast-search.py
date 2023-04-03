"""
https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D

1278ms 8.7mb

time - O(n(log n))
space - O(n) / without input
"""
n = int(input())
a = list(sorted(map(int, input().split())))
k = int(input())


def find_lesser(a, q):
    l = 0
    r = n

    while l < r:
        m = (l + r) // 2

        if a[m] < q:
            l = m + 1
        else:
            r = m

    return l


def find_greater(a, q):
    l = 0
    r = n

    while l < r:
        m = (l + r) // 2

        if a[m] > q:
            r = m
        else:
            l = m + 1

    return l


res = [0] * k
for i in range(k):
    l, r = map(int, input().split())

    res[i] = find_greater(a, r) - find_lesser(a, l)

print(*res)

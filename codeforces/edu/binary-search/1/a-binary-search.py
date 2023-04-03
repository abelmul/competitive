"""
https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A

811ms 8.6mb

time - O(log n)
space - O(1) / without input
"""
n, k = map(int, input().split())
a = list(map(int, input().split()))
queries = map(int, input().split())


def binary_search(a, q):
    l = 0
    r = len(a) - 1

    while l <= r:
        m = (l + r) // 2

        if a[m] == q:
            return True
        elif a[m] > q:
            r = m - 1
        else:
            l = m + 1
    return False


for q in queries:
    if binary_search(a, q):
        print("YES")
    else:
        print("NO")

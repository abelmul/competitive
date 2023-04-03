"""
https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B

701ms 8.6mb

time - O(log n)
space - O(1) / without input
"""
n, k = map(int, input().split())
a = list(map(int, input().split()))
queries = map(int, input().split())


def binary_search(a, q):
    l = 0
    r = n

    while l < r:
        m = (l + r) // 2

        if a[m] <= q:
            l = m + 1
        else:
            r = m

    return l


for q in queries:
    print(binary_search(a, q))

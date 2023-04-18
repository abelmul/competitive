"""
Lunch Rush

https://codeforces.com/gym/436386/problem/B

time = O(n)
space = O(1)
"""

n, k = map(int, input().split())

res = float("-inf")

for i in range(n):
    f, t = map(int, input().split())

    if t > k:
        f -= t - k

    res = max(res, f)


print(res)

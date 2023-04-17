"""
Kuriyama Mirai's Stones

https://codeforces.com/gym/431213/problem/C

Time - O(nlog(n))
Space - O(1)
"""

n = int(input())
v = list(map(int, input().split()))

a = sorted(v)

# calculate presum for both sorted and unsorted
for i in range(1, n):
    v[i] += v[i - 1]
    a[i] += a[i - 1]

for _ in range(int(input())):
    q, l, r = map(int, input().split())
    l -= 1  # convert to 0 index
    r -= 1  # convert to 0 index

    res = 0
    if q == 1:
        left = 0 if l < 1 else v[l - 1]
        res = v[r] - left
    elif q == 2:
        left = 0 if l < 1 else a[l - 1]
        res = a[r] - left

    print(res)

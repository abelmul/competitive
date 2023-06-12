"""
Greg and Array

https://codeforces.com/gym/443056/problem/D

Time - O(n + m + k)
Space - O(m + n)
"""


def do_presum(arr, n):
    for i in range(1, n):
        arr[i] += arr[i - 1]


n, m, k = map(int, input().split())
a = list(map(int, input().split()))

m_array = []
for i in range(m):
    m_array.append(list(map(int, input().split())))

delta_m = [0] * (m + 1)

for _ in range(k):
    x, y = map(int, input().split())

    # because it's one indexed
    delta_m[x - 1] += 1
    delta_m[y] -= 1
do_presum(delta_m, m)

delta = [0] * (n + 1)

for i in range(m):
    l, r, d = m_array[i]
    delta[l - 1] += d * delta_m[i]
    delta[r] -= d * delta_m[i]
do_presum(delta, n)

for i in range(n):
    a[i] += delta[i]

print(*a)

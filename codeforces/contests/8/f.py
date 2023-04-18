"""
Dormitory Number 

https://codeforces.com/gym/428258/problem/F

Time - O(n)
Space - O(n)
"""

n, s = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

presum_a = [a[0]]

for i in range(1, n):
    presum_a.append(presum_a[i - 1] + a[i])

current_idx = 0

for bi in b:
    while bi > presum_a[current_idx]:
        current_idx += 1

    print(current_idx + 1, bi - (presum_a[current_idx - 1] if current_idx > 0 else 0))

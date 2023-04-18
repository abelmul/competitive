"""
Max Pair 

https://codeforces.com/gym/429357/problem/B

Time - O(nlog(n) + mlog(m))
Space - O(1)
"""

n = int(input())
boys = list(map(int, input().split()))

m = int(input())
girls = list(map(int, input().split()))

boys.sort()
girls.sort()

b = 0
g = 0

pairs = 0

while b < n and g < m:
    diff = boys[b] - girls[g]
    if abs(diff) <= 1:
        pairs += 1
        b += 1
        g += 1

    elif diff < 0:
        b += 1
    else:
        g += 1

print(pairs)

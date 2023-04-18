"""
Who Advances to Next Round? 

https://codeforces.com/gym/422879/problem/A

Time - O(n)
Space - O(1)
"""

n, k = [int(i) for i in input().split()]
a = list(map(int, input().split()))[:n]

i = 0
while i < n and a[i] > 0 and a[i] >= a[k - 1]:
    i += 1

print(i)

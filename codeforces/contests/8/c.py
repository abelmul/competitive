"""
Buy Fruits 

https://codeforces.com/gym/428258/problem/C

Time - O(nlog(n) + m)
Space - O(n)
"""

n, m = map(int, input().split())
a = list(map(int, input().split()))

a.sort()

fruits = []
fruits_count = {}

for _ in range(m):
    fruits.append(input())
    fruits_count[fruits[-1]] = fruits_count.get(fruits[-1], 0) + 1

fruits = sorted(fruits, key=lambda f: -fruits_count[f])

max_price = []
min_price = []

left = 0
right = n - 1

for f in fruits:
    if f in fruits_count:
        max_price.extend([a[right]] * fruits_count[f])
        min_price.extend([a[left]] * fruits_count[f])

        left += 1
        right -= 1

        del fruits_count[f]

print(sum(min_price), sum(max_price))

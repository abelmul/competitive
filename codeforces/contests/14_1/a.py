"""
Elevetors

https://codeforces.com/gym/433716/problem/B

Time - O(1)
Space - O(1)
"""

for _ in range(int(input())):
    wt, et, ef = map(int, input().split())

    # go by elevetor all the way up
    res = (4 + ef) * et

    # walk all the way up
    res = min(res, 4 * wt)

    # walk to the elevetor
    res = min(res, ef * wt + (4 - ef) * et)

    print(res)

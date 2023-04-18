"""
Award

https://codeforces.com/gym/425122/problem/A

Time -  O(1)
Space - O(1)
"""

participants, pens, notebooks = map(int, input().split())

if participants <= pens and participants <= notebooks:
    print("YES")
else:
    print("NO")

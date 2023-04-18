"""
Min Unique Year

https://codeforces.com/gym/428258/problem/A

Time - O(n^n)
Space - O(1)
"""

y = input().strip()

found = False

while found == False:
    y = str(int(y) + 1)
    if len(set(y)) == 4:
        found = True

print(y)

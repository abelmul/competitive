"""
Outlets and Dividers

https://codeforces.com/gym/433716/problem/B

Time - O(nlog(n))
Space - O(n)
"""

for _ in range(int(input())):
    n, m = map(int, input().split())
    a = sorted(list(map(int, input().split())), reverse=True)

    count = 0
    res = 2  # we have 2 outlets first

    while count < m and res < n:
        # we subtract one as the input socket to the current a
        res += a[count] - 1

        count += 1

    print(count if res >= n else -1)

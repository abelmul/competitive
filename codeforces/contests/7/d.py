"""
Challenging Valleys

https://codeforces.com/gym/426951/problem/D

Time - O(n)
Space - O(1)
"""

t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    placeholder = 0
    seeker = placeholder

    found_subarray = False

    while placeholder < n and seeker < n:
        if seeker + 1 < n and a[seeker + 1] == a[placeholder]:
            seeker += 1

        elif (placeholder == 0 or a[placeholder - 1] > a[placeholder]) and (
            seeker == n - 1 or a[seeker] < a[seeker + 1]
        ):
            if found_subarray:
                found_subarray = False
                break
            found_subarray = True

            seeker += 1
            placeholder = seeker

        else:
            seeker += 1
            placeholder = seeker

    print("YES" if found_subarray else "NO")

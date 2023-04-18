"""
Sort

https://codeforces.com/gym/429357/problem/E

Time - O(n)
Space - O(n)
"""

for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))

    left_arr = []
    right_arr = []
    while arr:
        if len(left_arr) <= len(right_arr):
            left_arr.append(arr.pop())
        else:
            right_arr.append(arr.pop())

    res = []
    while left_arr or right_arr:
        if len(right_arr) == len(left_arr):
            if left_arr[-1] < right_arr[-1]:
                res.append(left_arr.pop())
            else:
                res.append(right_arr.pop())

            continue

        if len(right_arr) > len(left_arr):
            res.append(right_arr.pop())
        elif len(left_arr) > len(right_arr):
            res.append(left_arr.pop())

    if res == sorted(res):
        print("YES")
    else:
        print("NO")

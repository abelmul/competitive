for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    res = [0] * n

    l = 0
    r = n - 1
    i = 0

    while l <= r:
        res[i] = a[l]
        if i + 1 < n:
            res[i + 1] = a[r]

        i += 2
        r -= 1
        l += 1

    print(*res)

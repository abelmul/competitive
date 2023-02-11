for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()

    change = 0

    for i in range(k):
        if s[i] == "W":
            change += 1

    min_change = change

    for i in range(1, n - k + 1):
        if s[i - 1] == "W":
            change -= 1

        if s[i + k - 1] == "W":
            change += 1

        min_change = min(min_change, change)

    print(min_change)

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    seeker = 1
    next_is_negative = True if a[0] > 0 else False

    max_sum = 0
    max_number = a[0]

    while seeker < n:
        # print(n, seeker, a[seeker])
        if (next_is_negative and a[seeker] > 0) or (
            not next_is_negative and a[seeker] < 0
        ):
            max_number = max(max_number, a[seeker])
            seeker += 1
            continue

        max_sum += max_number
        next_is_negative = not next_is_negative
        max_number = a[seeker]

    max_sum += max_number

    print(max_sum)

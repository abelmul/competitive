#!/bin/python3

#
# Complete the 'countSwaps' function below.
#
# The function accepts INTEGER_ARRAY a as parameter.
#


def countSwaps(a):
    # Write your code here
    length = len(a)
    count_swap = 0

    for _ in range(length):
        for j in range(length - 1):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
                count_swap += 1

    print(f"Array is sorted in {count_swap} swaps.")
    print(f"First Element: {a[0]}")
    print(f"Last Element: {a[length-1]}")


if __name__ == "__main__":
    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    countSwaps(a)

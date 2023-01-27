#!/bin/python3
#
# Complete the 'insertionSort1' function below.
#
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER_ARRAY arr
#


def insertionSort1(n, arr):
    # Write your code here
    elem = arr[n - 1]
    j = n - 1
    while j > 0 and arr[j - 1] > elem:
        arr[j] = arr[j - 1]
        j -= 1
        print(*arr)

    arr[j] = elem
    print(*arr)


if __name__ == "__main__":
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    insertionSort1(n, arr)

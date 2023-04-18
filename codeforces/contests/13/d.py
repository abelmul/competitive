"""
Sum Of Digits

https://codeforces.com/gym/433100/problem/D

Time - O(n)
Space - O(n)
"""

import sys
import threading

input = lambda: sys.stdin.readline().strip()


def test(s, n, c) -> int:
    if n == 1:
        return int(s[0] != c)

    res1 = 0
    res2 = 0
    half = n // 2

    # check for the first half
    for i in range(half):
        if s[i] != c:
            res1 += 1

    # check the second half
    for i in range(half, n):
        if s[i] != c:
            res2 += 1

    return min(
        res1 + test(s[half:], half, chr(ord(c) + 1)),
        res2 + test(s[:half], half, chr(ord(c) + 1)),
    )


def main():
    for _ in range(int(input())):
        n = int(input())
        s = input()
        print(test(s, n, "a"))


if __name__ == "__main__":
    sys.setrecursionlimit(1 << 30)
    threading.stack_size(1 << 27)

    main_thread = threading.Thread(target=main)
    main_thread.start()
    main_thread.join()

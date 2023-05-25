import sys
import threading
from collections import defaultdict

input = lambda: sys.stdin.readline().strip()

"""
Rumor

https://codeforces.com/gym/444629/problem/C

Time - O(nlog(n))
Space - O(n)
"""

def dfs(d: defaultdict, visited: set, i: int):
    if i in visited:
        return

    visited.add(i)
    if i in d:
        for c in d[i]:
            dfs(d, visited, c)


def main():
    n, m = map(int, input().split())
    c = list(map(int, input().split()))

    d = defaultdict(list)

    for _ in range(m):
        x, y = map(int, input().split())

        d[x].append(y)
        d[y].append(x)

    min_bribe = sorted([(c[i], i) for i in range(n)])
    visited = set()

    res = 0
    if m == 0:
        res = sum(c)
    else:
        for b, i in min_bribe:
            if i + 1 not in visited:
                dfs(d, visited, i + 1)
                res += b

    print(res)


if __name__ == "__main__":
    sys.setrecursionlimit(1 << 30)
    threading.stack_size(1 << 27)

    main_thread = threading.Thread(target=main)
    main_thread.start()
    main_thread.join()

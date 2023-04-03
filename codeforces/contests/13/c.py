import sys
import threading

input = lambda: sys.stdin.readline().strip()

def helper(s: str) -> (int, int):
    length = len(s)
    if length == 1:
        return 0, int(s)

    count1, i1 = helper(s[:length//2])
    count2, i2 = helper(s[length//2:])

    s = i1 + i2

    if s >= 10:
        return 2 + count1 + count2, i1 + i2
    
    return 1 + count2 + count1, i1 + i2

def main():
    s = input()
    
    count = 0
    if int(s) >= 10:
        sum_ = sum(map(int, s))
        count = 1
        while sum_ >= 10:
            sum_ = sum(map(int,str(sum_)))
            count += 1

    print(count)


if __name__ == "__main__":

    sys.setrecursionlimit(1 << 30)
    threading.stack_size(1 << 27)

    main_thread = threading.Thread(target=main)
    main_thread.start()
    main_thread.join()
def is_palindrom(s):
    begin = 0
    end = len(s) - 1

    while begin < end:
        if s[begin] != s[end]:
            return False
        begin += 1
        end -= 1

    return True


for i in range(int(input())):
    s = list(input())
    if is_palindrom(s):
        s = sorted(s)
        print("-1" if is_palindrom(s) else "".join(s))
    else:
        print("".join(s))

for i in range(int(input())):
    n = int(input())
    
    a = list(map(int, input().split()))
    s = sum(a)
    
    if s == 0:
        print("NO")
    else:
        print("YES")
        if s > 0:
            print(*sorted(a, reverse=True))
        else:
            print(*sorted(a))

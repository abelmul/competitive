for i in range(int(input())):
    n = int(input())

    a = list(map(int, input().split()))
    res = "YES"

    a.sort()
    
    for i in range(1, n):
        if a[i] - a[i-1] > 1:
            res = "NO"
            break
    
    print(res)

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    
    l = 0
    r = n - 1
    """
    idea is to move all zeros to the left
    since r > l we can make j = r and i = l
    """
    ops = 0
    while l < r:
        if a[l] == 1 and a[r] == 0:
            ops += 1
            l += 1
            r -= 1
            continue

        if a[r] != 0:
            r -= 1
        
        if a[l] != 1:
            l += 1
        
    print(ops)

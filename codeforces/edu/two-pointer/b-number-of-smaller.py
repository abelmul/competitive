n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
 
ai = 0
bi = 0
 
length = 0
 
while ai < n or bi < m:
    next_element = float('inf')
    
    if bi == m or (ai < n and  a[ai] < b[bi]):
        length += 1
        ai += 1
    else:
        print(length, end=' ')
        bi += 1

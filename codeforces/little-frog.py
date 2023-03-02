n = int(input())

res = []

l = 1
r = n

while l < r:
    res.append(l)
    res.append(r)

    l += 1
    r -= 1
if l == r:
    res.append(l)

print(*res)

n = int(input())
a = sorted([int(i) for i in input().split()], reverse=True)

total_sum = sum(a)
sum_a = 0
res = n
for i in range(n):
    sum_a += a[i]

    if sum_a > total_sum - sum_a:
        res = i + 1
        break

print(res)

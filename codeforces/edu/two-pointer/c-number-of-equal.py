n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

ai = 0
bi = 0

num_equals = 0
dict_equal = {}

while ai < n and bi < m:
    next_element = float("inf")

    if a[ai] == b[bi]:
        aii = ai
        if a[ai] not in dict_equal:
            dict_equal[a[ai]] = 0
            while aii < n and a[aii] == b[bi]:
                dict_equal[a[ai]] += 1
                aii += 1
        num_equals += dict_equal[a[ai]]
        bi += 1
    elif a[ai] < b[bi]:
        ai += 1
    else:
        bi += 1

print(num_equals)

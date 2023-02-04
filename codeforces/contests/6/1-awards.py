participants, pens, notebooks = map(int, input().split())

if participants <= pens and participants <= notebooks:
    print("YES")
else:
    print("NO")

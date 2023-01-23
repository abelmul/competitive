t = int(input())
a = list(map(int, input().split()))[:t]

positive = []
negative = []
zero = []

for ai in a:
    if ai == 0:
        zero.append(ai)
    elif ai > 0:
        positive.append(ai)
    else:
        negative.append(ai)

if len(positive) == 0:
    positive.append(negative[-1])
    negative.pop()
    positive.append(negative[-1])
    negative.pop()
if len(negative) % 2 == 0:
    zero.append(negative.pop())

print(len(negative), " ".join(map(str, negative)))
print(len(positive), " ".join(map(str, positive)))
print(len(zero), " ".join(map(str, zero)))

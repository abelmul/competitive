k = int(input())
s = input()

char_count = {}
for c in s:
    char_count[c] = char_count.get(c, 0) + 1

segment = []
res = ""
for key, value in char_count.items():
    if value % k != 0:
        res = "-1"
        break
    segment.append(key * (value // k))

print("-1" if res == "-1" else "".join(segment * k))

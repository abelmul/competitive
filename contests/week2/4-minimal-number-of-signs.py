n = int(input())

patterns = [list(input()) for _ in range(n)]

out = ["?"] * len(patterns[0])

for p in patterns:
    for j, c in enumerate(p):
        if c != out[j]:
            if out[j] == "?":
                out[j] = c
            elif c != "?":
                out[j] = "0"

print("".join(out).replace("?", "z").replace("0", "?"))

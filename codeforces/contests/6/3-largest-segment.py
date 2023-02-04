n = int(input())

segments = []
for i in range(n):
    segments.append(tuple(map(int, input().split())))

segments_dict = {s: i for i, s in enumerate(segments)}
segments.sort()

index = 0
segment = segments[0]
found = True

for i in range(1, n):
    current_segment = segments[i]

    if current_segment[0] <= segment[0] and current_segment[1] >= segment[1]:
        segment = current_segment
        index = i
        continue
    elif current_segment[0] >= segment[0] and current_segment[1] <= segment[1]:
        continue
    else:
        found = False
        break

print(-1 if not found else segments_dict[segment] + 1)

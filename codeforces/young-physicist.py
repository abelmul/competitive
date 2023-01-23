t = int(input())

x, y, z = 0, 0, 0

for i in range(t):
    coordinates = list(map(int, input().split()))[:3]

    x += coordinates[0]
    y += coordinates[1]
    z += coordinates[2]


print("YES" if (x, y, z) == (0, 0, 0) else "NO")

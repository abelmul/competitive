x = 0

commands = int(input())

for i in range(commands):
    command = input()

    if "+" in [command[0], command[-1]]:
        x += 1
    elif "-" in [command[0], command[-1]]:
        x -= 1

print(x)

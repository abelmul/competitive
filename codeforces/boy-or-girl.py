s = input()

se = set()

for i in s:
    se.add(i)

if len(se) % 2 == 0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")

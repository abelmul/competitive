s1 = input()
s2 = input()

length = len(s1)

res = "0"

for i in range(length):
    o_c1 = ord(s1[i].lower())
    o_c2 = ord(s2[i].lower())
    
    if o_c1 > o_c2:
        res = "1"
        break
    elif o_c1 < o_c2:
        res = "-1"
        break
        
print(res)

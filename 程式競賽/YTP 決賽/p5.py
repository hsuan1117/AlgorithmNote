#p5
list1 = list(input().split(","))
for i in range(len(list1)):
    chararr = []
    for c in list1[i]:
        chararr.append(c)
    list1[i] = chararr
print(list1)
ask = input()
for n in ask:
    fullarr = []
    fullarr.append(n)
    for x in list1:
        if n in x :
            fullarr.append(x)
    print(fullarr)

# B,A,BA,A,,Z,K,F,,,,,,,,,,C,,,,,,Y,A,X
# ACKFP
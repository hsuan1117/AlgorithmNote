n = int(input().strip())

all = [int(x) for x in input().strip().split(' ')]

# print(all)
s = []
for i,x in enumerate(sorted(all)):
    if i == 0:
        s.append(x)
    else:    
        s.append(s[i-1] + x)

print(sum(s))


import sys
mem = []
for i in range(8):
    mem.append(int(sys.stdin.readline().strip()))
tmp = [0 for _ in range(100)]
N = int(sys.stdin.readline().strip())
for i in range(N):
    pd = list(sys.stdin.readline().strip().split(' '))
    if pd[0] == "LOAD":
        tmp[int(pd[1])] = mem[int(pd[2])]
    elif pd[0] == "ADD":
        tmp[int(pd[1])] = tmp[int(pd[2])] + tmp[int(pd[3])]
    elif pd[0] == "STORE":
        mem[int(pd[1])] = tmp[int(pd[2])]
    elif pd[0] == "MOVE":
        tmp[int(pd[1])] = tmp[int(pd[2])]

print(tmp[0])
print(mem[0])


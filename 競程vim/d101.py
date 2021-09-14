N = int(10)
DSU = [_ for _ in range(N)]

def find(idx):
    if idx == -1: return idx
    while not idx == DSU[idx]:
        idx = DSU[idx]
    return idx 

def mv(gp, gp2):
    a = find(gp)
    b = find(gp2)
    if a == n: return
    #if a not in DSU: a = gp
    #if b not in DSU: b = gp2 
    
    DSU[a]  = min(a,b)
    DSU[b]  = min(a,b)
    # DUS[gp2] = min(a,b) 

n,k = [int(x) for x in input().strip().split(' ')]
col = [int(x) for x in input().strip().split(' ')]
mod = [int(x) for x in input().strip().split(' ')]

m = 0x3f3f3f3f
#for _ in range(n): DSU[_]=_
for i,x in enumerate(col):
    if x == 0: 
        m = 0x3f3f3f3f
    else:
        DSU[i] = -1
        m = min(m, i)
        mv(m, i)

print(DSU)

def cango(x):
    return x>=0 and x<n

for x in mod:
    DSU[x] = -1
    if col[x-1] == 1:
        mv(x-1, x)
    if col[x+1] == 1:
        mv(x, x+1)
 
print(DSU) 

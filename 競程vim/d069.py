import sys

n,m = list(map(int, input().strip().split(' ')))

# print(n)

a = []
for _ in range(n):
    a.append([int(x) for x in input().strip().split(' ')])

def cango(x,y):
    return 0 <= x and x < n and 0 <= y and y < m

for x in range(n):
    for y in range(m):
        if cango(x-1, y) and cango(x, y-1):
            a[x][y] = max(a[x-1][y], a[x][y-1]) + a[x][y]
        elif cango(x-1, y):
            a[x][y] = a[x-1][y] + a[x][y]
        elif cango(x,y-1):
            a[x][y] = a[x][y-1] + a[x][y]
"""
for _ in a:
    print(_)
"""

print(a[n-1][m-1])

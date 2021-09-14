n = int(input().strip())

eny = list(map(int, input().strip().split(' ')))
our = list(map(int, input().strip().split(' ')))

eny.sort()
our.sort()
# print(eny)
# print(our)

omin = int(1e10)
emin = int(1e10)
cnt = 0
oi = 0

for i,o in enumerate(our):
    if o > eny[oi]:
        oi += 1
        cnt += 1


# print(min(eny))


print(cnt)

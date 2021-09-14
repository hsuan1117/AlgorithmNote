import random as rand

with open('num.in','w+') as f:
    for _ in range(int(1e4)):
        x = rand.randint(1,1e10)
        f.write(str(x)+' ')




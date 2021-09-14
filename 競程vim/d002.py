
import sys


a = [str(x) for x in sys.stdin.readline().strip().split(' ')]
num = []
#print(a)
for x in reversed(a):
    #print(num)
    # if x.isnumeric():
    #    num.append(int(x))
    if x == 'f':
        n = num[-1]
        #print(num)
        num.pop()
        #print(num)
        num.append(2*n-3)
    elif x == 'g':
        n = num[-1]
        num.pop()
        m = num[-1]
        num.pop()		
        num.append(2*n+m-7)
    elif x == 'h':
        n = num[-1]
        num.pop()	
        m = num[-1]
        num.pop()
        k = num[-1]
        num.pop()
        num.append(3*n-2*m+k)
    else:
        num.append(int(x))
print(num[0])	

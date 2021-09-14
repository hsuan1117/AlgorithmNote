import sys
import time

start = time.time()

a = list(map(int, sys.stdin.readline().strip().split(' ')))

end = time.time()
print(end -start)

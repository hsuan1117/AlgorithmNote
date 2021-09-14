import sys
import queue
import bisect
import time
n,l = map(int, sys.stdin.readline().strip().split(' ') )
all = [int(x) for x in sys.stdin.readline().strip().split(' ')]

q = queue.Queue()

q.put((all, l))
cnt = 0
while not q.empty():
    arr, L = q.get()
    # print(arr, end=' ')
    # print(L)
    if len(arr) == 0: continue
    # print(arr)
    # to find
    
    if len(arr) == 1:
        cnt = cnt + L
        continue
    if L == 1 and not len(arr) == 0:
        print(arr) 
        cnt = cnt +2
        continue

    mid = L // 2

    idx = 0
    for i,x in enumerate(arr):
        # print(x)
        if abs(x-mid) < abs(arr[idx]-mid):
            idx = i 
    # idx is in center
    # left = bisect.bisect_left(arr, mid) 
    # print("mid: " + str(mid) + " found: " + str(idx))
    # print(arr)
    cnt = cnt + L
    # print(cnt)
    a = arr[idx+1:] 
    if not len(a) == 0:
        q.put((a, mid))

    b = arr[:idx]
    if not len(b) == 0:
        q.put((b, mid))
    # time.sleep(3)
print(cnt)

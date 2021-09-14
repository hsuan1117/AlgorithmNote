# Q-6-4
N,t = [int(x) for x in input().strip().split(' ')]
all = [[int(x) for x in input().strip().split(' ')] for _ in range(N)]

#print(all)

dp  = [[-1, -1] for _ in range(N+5)]
now = [[-1, -1] for _ in range(N+5)]
for n,(i,j) in enumerate(all):
    #print(n) 
    if n == 0:
        #print(abs(t-i))
        dp[n][0] = abs(t-i)
        dp[n][1] = abs(t-j)
        now[n][0] = i
        now[n][1] = j
    else:
        # 第 n 關 調成 s th ( 0 / 1 ) 的成
        #print(dp[n-1][0], end=' + | ')
        #print(now[n-1][0] , end=' - ')
        #print(i)
        #print(dp[n-1][1], end=' + | ')
        #print(now[n-1][1], end=' - ')
        #print(j)
        dp[n][0] = min(dp[n-1][0] + abs(now[n-1][0] - i), dp[n-1][1] + abs(now[n-1][1] - i))
        now[n][0] = i
        dp[n][1] = min(dp[n-1][0] + abs(now[n-1][0] - j), dp[n-1][1] + abs(now[n-1][1] - j))
        now[n][1] = j

print(min(dp[N-1][0], dp[N-1][1]))

import os, psutil
process = psutil.Process(os.getpid())
print(process.memory_info().rss * (1e-6))  # in bytes 

del dp
del now

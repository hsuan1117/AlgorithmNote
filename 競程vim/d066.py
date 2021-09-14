import sys

N = int(sys.stdin.readline().strip())
dp = [0 for x in range(N+5)]

all = list(map(int, sys.stdin.readline().strip().split(' ')))
# print(all)

dp[0] = 0

for i in range(N):
    dp[i+1] = min(dp[i-1] + all[i], dp[i] + all[i])

print(dp[N])

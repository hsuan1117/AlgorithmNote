import sys

N = int(sys.stdin.readline())
sy = list(map(int, sys.stdin.readline().strip().split(' ')))

dp = [ 0 for _ in range(N+5)]

dp[0] = sy[0]
dp[1] = max(sy[0], sy[1])
for i in range(1,N):
    dp[i] = max(dp[i-1], dp[i-2]+sy[i])

print(dp[N-1])


n = int(input().strip())

s = [int(x) for x in input().strip().split(' ')]
# print(s)
dp = [0 for x in range(int(1e5))]

for i,x in enumerate(s):
    #print(x)
    if i == 0:
        dp[i] = x
    elif i == 1:
        dp[i] = x 
    elif i == 2:
        dp[i] = x + min(dp[i-1], dp[i-2])
    else:
        dp[i] = x + min(dp[i-1], dp[i-2], dp[i-3])

#print(dp) 
print(min(dp[n-1], dp[n-2]))
